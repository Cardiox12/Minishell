/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:55:42 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/18 23:27:50 by tlucille         ###   ########.fr       */
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

int		appropriate_exit_procedure(t_command *command)
{
	if (ft_strchr(command->value, '/') != NULL)
		perror("minishell");
	else if (g_flawed == 0)
	{
		write_error_invalid_command(command->value);
		free_command(command);
		ft_freetab(&g_env);
		exit(127);
	}
	free_command(command);
	ft_freetab(&g_env);
	if (g_flawed == 1)
		exit(1);
	else
		exit(127);
}

int		write_error_free_ret(t_command *command)
{
	perror("minishell");
	return (free_command_ret_fail(command));
}
