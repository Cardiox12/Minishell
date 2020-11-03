/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_on_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:32:55 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:32:57 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void	write_error_nofile(char *command_value)
{
	char to_write[ft_strlen(command_value) + 41];
	char *casted_write;

	casted_write = (char*)to_write;
	ft_bzero(casted_write, 41 + ft_strlen(command_value));
	ft_allocat(&casted_write, "minishell: ");
	ft_allocat(&casted_write, command_value);
	ft_allocat(&casted_write, ": No such file or directory\n");
	write(2, casted_write, ft_strlen(to_write));
}

void	write_error_invalid_command(char *command_value)
{
	char to_write[ft_strlen(command_value) + 32];
	char *casted_write;

	casted_write = (char*)to_write;
	ft_bzero(casted_write, 32 + ft_strlen(command_value));
	ft_allocat(&casted_write, "minishell: command not found: ");
	ft_allocat(&casted_write, command_value);
	ft_allocat(&casted_write, "\n");
	write(2, casted_write, ft_strlen(to_write));
}
