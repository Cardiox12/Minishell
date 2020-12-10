/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:57:17 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/11 00:46:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"
#include "ft_stdlib.h"
#include "builtins.h"

static int	check_signed_argument(char *arg)
{
	unsigned long long	ull;
	long long			ll;

	if (ft_strlen(arg + 1) > EXIT_TRUNC_CODE)
		return (FALSE);
	ull = ft_atoull(arg + 1);
	ll = ft_atoll(arg);
	if (ull > LLONG_MAX && ll != LLONG_MIN)
		return (FALSE);
	if (ll == LLONG_MIN)
		return (TRUE);
	return (ll >= LLONG_MIN || ull <= LLONG_MAX);
}

static int	check_unsigned_argument(char *arg)
{
	unsigned long long	ull;
	long long			ll;

	if (ft_strlen(arg) > EXIT_TRUNC_CODE)
		return (FALSE);
	ull = ft_atoull(arg);
	ll = ft_atoll(arg);
	if (ull > LLONG_MAX)
		return (FALSE);
	if (ll == LLONG_MIN)
		return (TRUE);
	return (ll >= LLONG_MIN || ull <= LLONG_MAX);
}

static int	is_valid_argument(char *arg)
{
	if (*arg == '+' || *arg == '-')
	{
		if (ft_isnumeric(arg + 1))
		{
			return (check_signed_argument(arg));
		}
	}
	if (ft_isnumeric(arg))
	{
		return (check_unsigned_argument(arg));
	}
	return (FALSE);
}

int			internal_exit(char **args)
{
	ft_printf("exit\n");
	if (args[1] == NULL)
		exit(g_exitstatus);
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
