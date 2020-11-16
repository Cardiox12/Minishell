/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:57:17 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:18:10 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"
#include "ft_stdlib.h"
#include "builtins.h"

int	internal_exit(char **args)
{
	(void)args;
	if (args[1] == NULL)
		exit(0);
	if (!ft_isnumeric(args[1]))
	{
		print_internal_error(BUILTINS_EXIT, args[1],
		ERROR_NUMERIC_ARG_REQUIRED, FALSE);
		exit(EXIT_ERR_NON_NUMERIC_ARG);
	}
	exit(ft_atoi(args[1]));
}
