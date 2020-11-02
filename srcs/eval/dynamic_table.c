/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:37:15 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/02 19:37:18 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "ft_strings.h"
#include "ft_stdlib.h"

static char		**ft_tab_copy_index(char ***dst, char **src, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (!((*dst)[i] = ft_strdup(src[i])))
			return (NULL);
		i++;
	}
	return (*dst);
}

void			ft_freetab_index(char ***tab, int index)
{
	int i;

	i = index;
	while (--i >= 0)
		ft_strdel(&((*tab)[i]));
	free(*tab);
	tab = NULL;
}

char			**add_to_dynamic_table(char ***table, char *str)
{
	int		limit;
	int		i;
	char	**temp_table;

	i = 0;
	limit = 5;
	while ((*table)[i])
	{
		if (i == limit)
			limit = limit * 2;
		i++;
	}
	if (i == limit)
	{
		limit = limit * 2;
		if (!(temp_table = ft_stabmaker(limit + 1)))
			return (NULL);
		ft_tab_copy_index(&temp_table, *table, i);
		ft_freetab_index(table, i);
		*table = temp_table;
	}
	if (!((*table)[i] = ft_strdup(str)))
		return (NULL);
	return (*table);
}
