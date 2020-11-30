/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:26:32 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/18 23:47:09 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/eval.h"
#include "builtins.h"

int		forked_builtin_child_exec(int out_redirect[2],
			int outpipe[2], t_command *command)
{
	if (command->output_type == PIPE || command->has_output_redirect == 1)
	{
		close(outpipe[0]);
		if (command->has_output_redirect == 1)
		{
			close(out_redirect[0]);
			dup2(out_redirect[1], 1);
			close(out_redirect[1]);
		}
		else if (command->output_type == PIPE)
			dup2(outpipe[1], 1);
		close(outpipe[1]);
	}
	else
		close_pipe(outpipe);
	g_exitstatus = 0;
	builtins_call(command);
	exit(g_exitstatus);
	return (0);
}

int		builtin_fork_exec(t_command *command,
			int out_redirect[2], int outpipe[2])
{
	int pid;
	int status;

	pid = fork();
	if (pid == 0)
		forked_builtin_child_exec(out_redirect, outpipe, command);
	else
	{
		close_pipe(outpipe);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exitstatus = WEXITSTATUS(status);
	}
	return (0);
}

int		redirect_handler(int out_redirect[2],
			int outpipe[2], t_command *command)
{
	char	*output_buffer;

	if (g_flawed == 1)
		return (0);
	if (command->has_output_redirect == 1)
	{
		close_pipe(outpipe);
		close(out_redirect[1]);
		if (!(output_buffer = read_until_eof(out_redirect[0])))
			return (free_command_ret_fail(command));
		write_redirections(command, output_buffer);
		ft_strdel(&output_buffer);
		close(out_redirect[0]);
	}
	return (0);
}

int		recursive_builtin(t_command *command, int oldpipe[2], int outpipe[2])
{
	int				out_redirect[2];

	if (command->has_output_redirect == 1)
		pipe(out_redirect);
	if (oldpipe != NULL)
		close_pipe(oldpipe);
	builtin_fork_exec(command, out_redirect, outpipe);
	if (redirect_handler(out_redirect, outpipe, command) == -1)
		return (-1);
	free_command(command);
	exit(g_exitstatus);
	return (0);
}
