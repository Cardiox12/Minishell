/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   craft_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:09:25 by tlucille          #+#    #+#             */
/*   Updated: 2020/12/07 00:29:43 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "eval.h"
#include "lexer.h"

int			pre_initialize_command(t_command *command)
{
	if (!(command->args = ft_stabmaker(6)))
		return (-1);
	if (!(command->value = expand(g_queue->token.value, g_queue->token.type)))
		return (free_tab_ret_fail(&(command->args)));
	if (!(add_to_dynamic_table(&(command->args), command->value)))
		return (free_tab_string_ret_fail(&(command->value), &(command->args)));
	if (!(command->path = get_path(command->value))
		&& !(is_builtin(command->args)))
		return (free_tab_string_ret_fail(&(command->value), &(command->args)));
	g_queue = g_queue->next;
	if (g_queue == NULL)
		return (0);
	if (g_queue->token.type == PIPE)
	{
		command->output_type = PIPE;
		return (0);
	}
	return (0);
}

int			finish_command(t_command *command)
{
	if (g_queue && g_queue->token.type == PIPE)
	{
		command->output_type = g_queue->token.type;
		g_queue = g_queue->next;
		return (1);
	}
	else
		command->output_type = -1;
	if (g_queue && g_queue->token.type == OPERATOR)
	{
		g_queue = g_queue->next;
		return (1);
	}
	return (0);
}

int			get_redirects(int *count, t_command *command)
{
	while (g_queue && g_queue->token.type == REDIRECTION
		&& (g_queue->token.value)[0] == '>')
	{
		if (get_output_redirections(command, g_queue) == -1)
			return (-1);
		g_queue = g_queue->next->next;
		(*count)++;
	}
	while (g_queue && g_queue->token.type == REDIRECTION
		&& (g_queue->token.value)[0] == '<')
	{
		if (get_input_redirections(command, g_queue) == -1)
			return (-1);
		g_queue = g_queue->next->next;
		(*count)++;
	}
	return (0);
}

int			get_args(int *count, t_command *command)
{
	while (g_queue && is_arg(g_queue))
	{
		if (!(add_to_dynamic_table(&(command->args), g_queue->token.value)))
			return (free_command_ret_fail(command));
		g_queue = g_queue->next;
		(*count)++;
	}
	return (0);
}

int			craft_command(t_command *command)
{
	int	count;
	int	initialize_ret;

	count = 0;
	init_command(command);
	while (g_queue != NULL && g_queue->token.type != PIPE)
	{
		if (g_queue->token.type == COMMAND)
		{
			if ((initialize_ret = pre_initialize_command(command)) == -1)
				return (-1);
		}
		if ((get_args(&count, command)) == -1)
			return (-1);
		if ((get_redirects(&count, command)) == -1)
			return (-1);
		if (finish_command(command))
			break ;
	}
	if (g_queue && g_queue->token.type == PIPE)
		g_queue = g_queue->next;
	return (0);
}
