/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_piper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:30:17 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:30:18 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "builtins.h"

int		child_exec(t_command *command, int oldpipe[2], int newpipe[2])
{
	int		redirectpipe[2];
	
	close(oldpipe[1]);
//	ft_printf("oldpipe[0] %d\n", oldpipe[0]);
//	ft_printf("oldpipe[1] %d\n", oldpipe[1]);
	if (command->has_input_redirect)
	{
		if (close(oldpipe[1]))
			perror("close old in child_exec");
		pipe(redirectpipe);
//		ft_printf("has input");
		read_redirections_pipe(command, redirectpipe);
		dup2(redirectpipe[0], 0);
		close(redirectpipe[0]);
	}
	else
	{
		dup2(oldpipe[0], 0);
		close(oldpipe[0]);
	}
	if (command->output_type == PIPE || command->has_output_redirect == 1)
	{
		close(newpipe[0]);
		dup2(newpipe[1], 1);
		if (close(newpipe[1]) == -1)
			perror("close");
	}
//	dup2(newpipe[1], oldpipe[1]);
	if (execve(command->path, command->args, g_env) == -1)
	{
		write_error_nofile(command->value);
		free_command(command);
		exit(127);
	}
	return (0);
}

int		parent_exec(int oldpipe[2], int newpipe[2], t_command *command)
{
	char	*output_buffer;

	if (close(oldpipe[0]) == -1)
		perror("close old parent");
	if (close(oldpipe[1]) == -1)
		perror("close old parent");
	if (command->has_output_redirect == 1)
	{
		if (close(newpipe[1]) == -1)
			perror("close in parent exec");
		if (!(output_buffer = read_until_eof(newpipe[0])))
			return (free_command_ret_fail(command));
//		ft_printf("output_buffer: %s\n", output_buffer);
		write_redirections(command, output_buffer);
		if (close(newpipe[0]) == -1)
			perror("close");
		ft_strdel(&output_buffer);
	}
	return (0);
}

int		recur_parent_exec(int oldpipe[2], int newpipe[2],
			t_command *new_command, pid_t pid)
{
	int		status;

	if (parent_exec(oldpipe, newpipe, new_command) == -1)
		return (-1);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exitstatus = WEXITSTATUS(status);
	if (new_command->has_output_redirect && new_command->output_type == PIPE)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if (new_command->output_type == PIPE)
	{
		if ((recursive_piper(newpipe)) == -1)
			return (free_command_ret_fail(new_command));
	}
	free_command(new_command);
	return (0);
}

int		recursive_piper(int oldpipe[2])
{
	int				newpipe[2];
	t_command		new_command;
	pid_t			pid;

	if (g_queue == NULL)
		return (0);
	if (craft_command(&new_command) == -1)
		return (-1);
//	print_s_command(&new_command);
	if (is_builtin(new_command.args))
		return (recursive_builtin(&new_command));
	if (new_command.output_type == PIPE || new_command.has_output_redirect == 1)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (free_command_ret_fail(&new_command));
	}
	else if (pid == 0)
		return (child_exec(&new_command, oldpipe, newpipe));
	else
		return (recur_parent_exec(oldpipe, newpipe, &new_command, pid));
}
