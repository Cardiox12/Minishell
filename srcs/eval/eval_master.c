/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:39:17 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/18 23:46:20 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "eval.h"
#include "lexer.h"

int		is_arg(t_queue *queue)
{
	int		type;

	if (queue == NULL)
		return (0);
	type = queue->token.type;
	if (type == STRING || type == ARGUMENT
		|| type == OPTION || type == RAW_STRING || type == ENV_VARIABLE)
		return (1);
	else
		return (0);
}

int		is_output(t_queue *queue)
{
	int		type;

	if (queue == NULL)
		return (0);
	type = queue->token.type;
	if (type == REDIRECTION || type == PIPE)
		return (1);
	else
		return (0);
}

int		launch_adequate_execution(t_command *command)
{
	print_s_command(command);
//	ft_printf("g_flawed: %d\n", g_flawed);
	if (command->value == NULL || g_flawed == 1)
	{
		ft_printf("here\n");
		if (g_flawed == 1)
			g_exitstatus = 1;
		free_command(command);
//		g_queue = g_queue->next;
		return (0);
	}
	if (command->output_type == PIPE)
	{
		if (init_piper(command) == -1)
			return (-1);
	}
	else
	{
		if (is_builtin(command->args))
		{
			if (g_flawed == 0)
			{
				if (simple_builtin(command) == -1)
					return (-1);
			}
			else
				g_exitstatus = 1;
		}
		else
		{
//			if (g_flawed == 0)
//			{}
			if (fork_and_exec(command) == -1)
				return (-1);
		}
	}
	return (0);
}

int		eval(t_queue *queue)
{
	t_command	command;
	int			craft_ret;

	g_queue = queue;
	g_in_eval = 1;
	while (g_queue)
	{
//		if (g_queue->token.type == COMMAND)
//		{
			ft_printf("boucle");
			ft_printf("queue value: %s\n", g_queue->token.value);
			command.value = NULL;
			if ((craft_ret = craft_command(&command)) == -1)
				return (-1);
			if (launch_adequate_execution(&command) == -1)
				return (-1);
			ft_printf("post adequate\n");
			ft_printf("queue value: %s\n", g_queue->token.value);
			if (g_queue == NULL)
			{
				g_in_eval = 0;
				return (0);
			}
			if (g_queue->token.type == OPERATOR)
				g_queue = g_queue->next;
//		}
	}
	g_in_eval = 0;
	return (0);
}
