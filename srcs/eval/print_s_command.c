/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:24:07 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:24:08 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/eval.h"

void	print_s_command(t_command *command)
{
	ft_printf("\n============== content of t_command ==============\n\n");
	ft_printf("value: %s\n", command->value);
	ft_printtab(command->args);
	ft_printf("path: %s\n", command->path);
	if (command->has_output_redirect == 1)
	{
		ft_printf("output redirection fds : \n");
		ft_print_int_tab(command->output_redirection_files);
	}
	if (command->has_input_redirect == 1)
	{
		ft_printf("input redirection fds : \n");
		ft_print_int_tab(command->input_redirection_files);
	}
	if (command->output_type == PIPE)
		ft_printf("output: %s\n", "PIPE");
	if (command->output_type == REDIRECTION)
		ft_printf("output: %s\n", "REDIRECTION");
	if (command->output_type == -1)
		ft_printf("output: %s\n", "STDOUT");
	ft_printf("\n==============          end         ==============\n\n");
}
