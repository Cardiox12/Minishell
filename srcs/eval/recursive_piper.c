/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_piper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:30:17 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/18 23:35:51 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "builtins.h"

int		child_input_redirects(t_command *command)
{
	int		redirectpipe[2];

	pipe(redirectpipe);
	read_redirections_pipe(command, redirectpipe);
	dup2(redirectpipe[0], 0);
	close(redirectpipe[0]);
	return (0);
}

int		child_exec(t_command *command, int oldpipe[2], int outpipe[2])
{
//	ft_printf("exec_pid: %d\n", getpid());
//	ft_printf("%s in exec\n", command->value);
	close(oldpipe[1]);
	if (command->has_input_redirect)
		child_input_redirects(command);
	else
	{
		dup2(oldpipe[0], 0);
		close(oldpipe[0]);
	}
	if (command->output_type == PIPE || command->has_output_redirect == 1)
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

int		parent_exec(int oldpipe[2], int outpipe[2], t_command *command)
{
	char	*output_buffer;

	close(oldpipe[0]);
	close(oldpipe[1]);
	if (command->has_output_redirect == 1)
	{
		close(outpipe[1]);
		if (!(output_buffer = read_until_eof(outpipe[0])))
			return (free_command_ret_fail(command));
		write_redirections(command, output_buffer);
		close(outpipe[0]);
		ft_strdel(&output_buffer);
	}
	return (0);
}

int		recur_parent_exec(int oldpipe[2], int outpipe[2],
			t_command *new_command, pid_t pid)
{
	int		status;

	g_exec_pid = pid;
	if (parent_exec(oldpipe, outpipe, new_command) == -1)
		return (-1);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exitstatus = WEXITSTATUS(status);
	g_exec_pid = -1;
//	if (new_command->has_output_redirect && new_command->output_type == PIPE)
//	{
//		if (pipe(newpipe) == -1)
//			perror("pipe");
//	}
//	if (new_command->output_type == PIPE)
//	{
//		if ((recursive_piper(newpipe)) == -1)
//			return (free_command_ret_fail(new_command));
//	}
	free_command(new_command);
	exit(g_exitstatus);
	return (0);
}

int		recursive_piper(t_command *command, int oldpipe[2], int outpipe[2])
{
//	t_command		new_command;
	pid_t			pid;

//	ft_printf("%s in recursive\n", command->value);
//	if (g_queue == NULL)
//		return (0);
	if (g_flawed == 1 || command->value == NULL)
		return (0);
	if (is_builtin(command->args))
		return (recursive_builtin(command, oldpipe, outpipe));
	if ((pid = fork()) == -1)
		return (free_command_ret_fail(command));
	else if (pid == 0)
		return (child_exec(command, oldpipe, outpipe));
	else
		return (recur_parent_exec(oldpipe, outpipe, command, pid));
}
