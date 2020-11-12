/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:51:57 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:51:58 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "builtins.h"

int		is_builtin(char **args)
{
	int		index;
	int		size;

	index = 0;
	size = ft_strlen(*args);
	if (size == 0)
		return (0);
	while (index < BUILTINS_SIZE)
	{
		if (ft_strncmp(g_builtins[index].func_name, *args, size) == 0)
			return (1);
		index++;
	}
	return (0);
}
