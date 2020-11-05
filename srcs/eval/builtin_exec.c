/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:15:35 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/02 19:15:38 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/eval.h"
#include "builtins.h"

extern t_queue	*g_queue;

int		simple_builtin_exec(t_command *command, int newpipe[2])
{
	int		pid;
	int		status;
//	int		temp_stdout;

//	temp_stdout = dup(1);
	if (command->has_output_redirect == 1
		&& (ft_strncmp(command->value, "env", 3) == 0 
		|| ft_strncmp(command->value, "echo", 4) == 0
		|| ft_strncmp(command->value, "pwd", 3) == 0))
	{
		pid = fork();
		if (pid == 0)
		{
			close(newpipe[0]);
			dup2(newpipe[1], 1);
			close(newpipe[1]);
			g_exitstatus = 0;
			builtins_call(command->args);
			exit(g_exitstatus);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				g_exitstatus = WEXITSTATUS(status);
		}
	}
	else
		builtins_call(command->args);	
	return (0);
}

int		simple_redirect_handler(int newpipe[2], t_command *command)
{
	char	*output_buffer;

	if (command->has_output_redirect == 1)
	{
		close(newpipe[1]);
		if (!(output_buffer = read_until_eof(newpipe[0])))
		{
			close(newpipe[0]);
			return (-1);
		}
		write_redirections(command, output_buffer);
	}
	return (0);
}

int		simple_builtin(t_command *command)
{
	int				newpipe[2];

	if (command->has_output_redirect == 1)
		pipe(newpipe);
	simple_builtin_exec(command, newpipe);
	if (simple_redirect_handler(newpipe, command) == -1)
		return (free_command_ret_fail(command));
	return (0);
}
