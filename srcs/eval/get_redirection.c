/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:59:59 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/18 23:27:32 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int				g_flawed = 0;

static int		is_simple_redirect(t_queue *queue)
{
	if (ft_strlen(queue->token.value) == 1)
		return (1);
	else
		return (0);
}

int				get_output_redirections(t_command *command, t_queue *queue)
{
	int		fd;

	if (command->has_output_redirect == 0)
	{
		command->has_output_redirect = 1;
		if (!(command->output_redirection_files = ft_int_tab_maker(6)))
		{
			command->has_output_redirect = 0;
			return (free_command_ret_fail(command));
		}
	}
	if (is_simple_redirect(queue))
		fd = open(queue->next->token.value, O_RDWR | O_CREAT | O_TRUNC, 0666);
	else
		fd = open(queue->next->token.value, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (write_error_free_ret(command));
	else
	{
		if (!(add_to_dynamic_int_array(&(command->output_redirection_files),
			fd)))
			return (free_command_ret_fail(command));
	}
	return (0);
}

int				get_input_redirections(t_command *command, t_queue *queue)
{
	int		fd;

	if (command->has_input_redirect == 0)
	{
		command->has_input_redirect = 1;
		if (!(command->input_redirection_files = ft_int_tab_maker(6)))
		{
			command->has_output_redirect = 0;
			return (free_command_ret_fail(command));
		}
	}
	fd = open(queue->next->token.value, O_RDONLY, 0666);
	if (fd == -1)
	{
		write_error_nofile(queue->next->token.value);
		g_flawed = 1;
	}
	else
	{
		if (!(add_to_dynamic_int_array(&(command->input_redirection_files),
			fd)))
			return (free_command_ret_fail(command));
	}
	return (0);
}
