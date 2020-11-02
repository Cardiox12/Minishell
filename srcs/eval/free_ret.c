/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:55:42 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/02 19:55:44 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		free_command_ret_fail(t_command *command)
{
	free_command(command);
	return (-1);
}

int		free_tab_ret_fail(char ***tab)
{
	ft_freetab(tab);
	return (-1);
}

int		free_tab_string_ret_fail(char **string, char ***tab)
{
	ft_strdel(string);
	ft_freetab(tab);
	return (-1);
}

int		write_error_free_ret(t_command *command)
{
	perror("open");
	return (free_command_ret_fail(command));
}