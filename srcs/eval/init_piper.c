/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:21:54 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/18 23:33:58 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "builtins.h"

int		init_return_parent(int out_redirect[2], t_command *command, pid_t pid)
{
	int		status;
	char	*output_buffer;

	g_exec_pid = pid;
	if (command->has_output_redirect == 1)
	{
		close(out_redirect[1]);
		if (!(output_buffer = read_until_eof(out_redirect[0])))
			return (free_command_ret_fail(command));
		close(out_redirect[0]);
		write_redirections(command, output_buffer);
		ft_strdel(&output_buffer);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exitstatus = WEXITSTATUS(status);
	g_exec_pid = -1;
	free_command(command);
	exit(g_exitstatus);
	return (0);
}

int		init_child_exec(int out_redirect[2], int inputpipe[2], int outpipe[2], t_command *command)
{
	if (command->has_input_redirect == 1)
	{
		read_redirections_nopipe(command, inputpipe);
		dup2(inputpipe[0], 0);
		close(inputpipe[0]);
		close(inputpipe[1]);
	}
	if (command->has_output_redirect)
	{
		close_pipe(outpipe);
		close(out_redirect[0]);
		dup2(out_redirect[1], 1);
		close(out_redirect[1]);
	}
	else
	{
		close(outpipe[0]);
		dup2(outpipe[1], 1);
		close(outpipe[1]);
	}
	if (g_flawed == 0)
	{
		if (execve(command->path, command->args, g_env) == -1)
			appropriate_exit_procedure(command);
	}
	else
		exit(1);
	return (0);
}

int		init_piper(int outpipe[2], t_command *command)
{
	int				inputpipe[2];
	int				out_redirect[2];
	pid_t			pid;

	if (is_builtin(command->args))
		return (recursive_builtin(command, NULL, outpipe));
	if (command->has_output_redirect == 1)
		pipe(out_redirect);
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (free_command_ret_fail(command));
	}
	if (pid == 0)
	{
		if (command->has_input_redirect == 1)
			pipe(inputpipe);
		if (init_child_exec(out_redirect, inputpipe, outpipe, command) == -1)
			return (-1);
	}
	else
	{
		close_pipe(outpipe);
		return (init_return_parent(out_redirect, command, pid));
	}
	return (0);
}
