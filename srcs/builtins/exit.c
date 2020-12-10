/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:57:17 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 01:12:14 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"
#include "ft_stdlib.h"
#include "builtins.h"

static int	is_valid_argument(char *arg)
{
	if (*arg == '+' || *arg == '-')
	{
		if (ft_isnumeric(arg + 1))
			return (TRUE);
	}
	return (ft_isnumeric(&arg[1]));
}

int			internal_exit(char **args)
{
	ft_printf("exit\n");
	if (args[1] == NULL)
		exit(0);
	if (!is_valid_argument(args[1]))
	{
		print_internal_error(BUILTINS_EXIT, args[1],
		ERROR_NUMERIC_ARG_REQUIRED, FALSE);
		exit(EXIT_ERR_NON_NUMERIC_ARG);
	}
	else if (ft_tablen(args) > 2)
		print_error_no_param(BUILTINS_EXIT, ERROR_TOO_MANY_ARGUMENTS);
	else
		exit(ft_atoi(args[1]));
	return (FAILURE);
}
