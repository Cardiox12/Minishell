/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:39:17 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 03:10:24 by bbellavi         ###   ########.fr       */
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
	if (command->output_type == PIPE)
	{
		if (init_piper(command) == -1)
			return (-1);
	}
	else
	{
		if (is_builtin(command->args))
		{
			if (simple_builtin(command) == -1)
				return (-1);
		}
		else
		{
			if (fork_and_exec(command) == -1)
				return (-1);
		}
	}
	return (0);
}

int		eval(t_queue *queue)
{
	t_command	command;

	g_queue = queue;
//	signal(SIGQUIT, )
	g_in_eval = 1;
//	ft_printf("in eval\n");
	while (g_queue)
	{
		if (g_queue->token.type == COMMAND)
		{
			if (craft_command(&command) == -1)
				return (-1);
//			print_s_command(&command);
			if (launch_adequate_execution(&command) == -1)
				return (-1);
			if (g_queue == NULL)
			{
				g_in_eval = 0;
//				ft_printf("out eval\n");
				return (0);
			}
			if (g_queue->token.type == OPERATOR)
				g_queue = g_queue->next;
//			else
//				ft_printf("untracked symbol in eval %s\n",
//					g_queue->token.value);
		}
	}
	g_in_eval = 0;
//	ft_printf("out eval\n");
	return (0);
}
