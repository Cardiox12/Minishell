/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:21:54 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:21:55 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "builtins.h"

int		init_return_parent(int newpipe[2], t_command *command, pid_t pid)
{
	int		status;
	char	*output_buffer;

	if (command->has_output_redirect == 1)
	{
		close(newpipe[1]);
		if (!(output_buffer = read_until_eof(newpipe[0])))
			return (free_command_ret_fail(command));
		close(newpipe[0]);
		write_redirections(command, output_buffer);
		if (pipe(newpipe) == -1)
			perror("pipe");
		ft_strdel(&output_buffer);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exitstatus = WEXITSTATUS(status);
	if ((recursive_piper(newpipe)) == -1)
		return (free_command_ret_fail(command));
	free_command(command);
	return (0);
}

int		init_child_exec(int inputpipe[2], int newpipe[2], t_command *command)
{
	if (command->has_input_redirect == 1)
	{
		read_redirections_nopipe(command, inputpipe);
		dup2((inputpipe)[0], 0);
		close((inputpipe)[1]);
	}
	dup2(newpipe[1], 1);
	if (execve(command->path, command->args, g_env) == -1)
		appropriate_exit_procedure(command);
	return (0);
}

int		init_piper(t_command *command)
{
	int				newpipe[2];
	int				inputpipe[2];
	pid_t			pid;

	if (is_builtin(command->args))
		return (recursive_builtin(command));
	ft_bzero(inputpipe, 2);
	if (pipe(newpipe) == -1)
		perror("pipe");
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (free_command_ret_fail(command));
	}
	if (pid == 0)
	{
		close(newpipe[0]);
		if (command->has_input_redirect == 1)
			pipe(inputpipe);
		if (init_child_exec(inputpipe, newpipe, command) == -1)
			return (-1);
	}
	else
		return (init_return_parent(newpipe, command, pid));
	return (0);
}
