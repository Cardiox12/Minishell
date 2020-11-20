/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:57:39 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/20 13:57:43 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void	init_command(t_command *command)
{
	command->value = NULL;
	command->args = 0;
	g_flawed = 0;
	command->has_output_redirect = 0;
	command->has_input_redirect = 0;
	command->path = NULL;
}
