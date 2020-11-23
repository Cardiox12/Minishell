/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:54:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 11:27:19 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internals.h"
#include "internal_errors.h"

int			export(char **args)
{
	size_t	size;

	size = ft_tablen(args);
	if (size == 1)
		return (export_none());
	if (size == 2)
	{
		return (parse_by_one(args));
	}
	else if (size == 3)
	{
		return (parse_by_two(args));
	}
	else if (size == 4)
	{
		return (parse_by_three(args));
	}
	return (SUCCESS);
}
