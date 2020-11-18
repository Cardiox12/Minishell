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

int		forked_builtin_child_exec(int newpipe[2], t_command *command)
{
	if (g_flawed == 1)
		return (0);
	if (command->output_type == PIPE || command->has_output_redirect == 1)
	{
		close(newpipe[0]);
		dup2(newpipe[1], 1);
		if (close(newpipe[1]) == -1)
			perror("close");
	}
	g_exitstatus = 0;
	builtins_call(command);
	exit(g_exitstatus);
	return (0);
}

int		builtin_fork_exec(t_command *command, int newpipe[2])
{
	int pid;
	int status;

	if (g_flawed == 1)
	{
		return (0);
		g_exitstatus = 1;
	}
	if (ft_strncmp(command->value, "env", 3) == 0
		|| ft_strncmp(command->value, "echo", 4) == 0
		|| ft_strncmp(command->value, "pwd", 3) == 0
		|| (ft_strncmp(command->value, "export", 6) == 0
			&& ft_tablen(command->args) == 1))
	{
		pid = fork();
		if (pid == 0)
			forked_builtin_child_exec(newpipe, command);
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				g_exitstatus = WEXITSTATUS(status);
		}
	}
	return (0);
}

int		redirect_handler(int newpipe[2], t_command *command)
{
	char	*output_buffer;

	if (g_flawed == 1)
		return (0);
	if (command->has_output_redirect == 1)
	{
		close(newpipe[1]);
		if (!(output_buffer = read_until_eof(newpipe[0])))
			return (free_command_ret_fail(command));
		write_redirections(command, output_buffer);
		ft_strdel(&output_buffer);
		close(newpipe[0]);
	}
	return (0);
}

int		recursive_builtin(t_command *command)
{
	int				newpipe[2];
	int				piper_return;

	if (command->output_type == PIPE || command->has_output_redirect == 1)
		pipe(newpipe);
	builtin_fork_exec(command, newpipe);
	if (redirect_handler(newpipe, command) == -1)
		return (-1);
	if (command->has_output_redirect && command->output_type == PIPE)
	{
		close(newpipe[1]);
		close(newpipe[0]);
		if (pipe(newpipe) == -1)
			perror("pipe");
		close(newpipe[0]);
		close(newpipe[1]);
	}
	if (command->output_type == PIPE)
	{
		if ((piper_return = recursive_piper(newpipe)) == -1)
			return (-1);
	}
	free_command(command);
	return (0);
}
