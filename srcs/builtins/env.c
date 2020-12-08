/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:31:18 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/08 23:31:23 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"
#include "builtins.h"

static int	print_env_error(char *arg)
{
	ft_putstr_fd(BUILTINS_ENV, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putchar_fd('\'', STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putchar_fd('\'', STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("No such file or directory\n", STDERR_FILENO);
	return (ENV_ERR_FILE_NOT_FOUND);
}

int	env(char **args)
{
	size_t index;

	index = 0;
	if (args[1] != NULL)
		return (print_env_error(args[1]));
	while (g_env[index] != NULL)
	{
		if (ft_strchr(g_env[index], SYM_EQUAL) != NULL)
			ft_printf("%s\n", g_env[index]);
		index++;
	}
	return (0);
}
