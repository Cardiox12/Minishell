/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:54:02 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/18 23:31:56 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		fork_child_exec(int pipefd[2], t_command *command)
{
	int inputpipe[2];

	if (command->has_output_redirect == 1)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
	}
	if (command->has_input_redirect == 1)
	{
		pipe(inputpipe);
		read_redirections_nopipe(command, inputpipe);
		dup2(inputpipe[0], 0);
		close(inputpipe[0]);
		close(inputpipe[1]);
	}
	if (g_flawed == 0)
	{
		if (execve(command->path, command->args, g_env) == -1)
			appropriate_exit_procedure(command);
	}
	else
		exit(1);
	return (1);
}

int		return_fork_parent(t_command *command, int pipefd[2], pid_t pid)
{
	int		status;
	char	*output_buffer;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exitstatus = WEXITSTATUS(status);
	if (command->has_output_redirect == 1)
	{
		close(pipefd[1]);
		if (!(output_buffer = read_until_eof(pipefd[0])))
			return (free_command_ret_fail(command));
		write_redirections(command, output_buffer);
		ft_strdel(&output_buffer);
		close(pipefd[0]);
	}
	free_command(command);
	return (0);
}

int		fork_and_exec(t_command *command)
{
	pid_t	pid;
	int		pipefd[2];

	if (command->has_output_redirect == 1)
		pipe(pipefd);
	if ((pid = fork()) == -1)
		return (free_command_ret_fail(command));
	else if (pid == 0)
		return (fork_child_exec(pipefd, command));
	else
		return (return_fork_parent(command, pipefd, pid));
}
