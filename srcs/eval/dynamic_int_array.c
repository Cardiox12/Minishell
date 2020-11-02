/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:21:21 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/02 19:21:24 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static int		*ft_int_tab_copy_index(int **dst, int *src, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		(*dst)[i] = src[i];
		i++;
	}
	return (*dst);
}

int				*add_to_dynamic_int_array(int **table, int nbr)
{
	int		limit;
	int		i;
	int		*temp_table;

	i = 0;
	limit = 5;
	while ((*table)[i] != -1)
	{
		if (i == limit)
			limit = limit * 2;
		i++;
	}
	if (i == limit)
	{
		limit = limit * 2;
		if (!(temp_table = ft_int_tab_maker(limit + 1)))
			return ((void*)0);
		ft_int_tab_copy_index(&temp_table, *table, i);
		free(*table);
		*table = temp_table;
	}
	(*table)[i] = nbr;
	return (*table);
}
