/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 04:12:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:38:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_objects.h"
#include "ft_strings.h"
#include "ft_stdlib.h"

static char	**string_list_items_malloc(t_string_list *items, int len)
{
	char	**items2;

	if (items->items == NULL)
		items2 = malloc(sizeof(char*));
	else
	{
		items2 = ft_realloc(items->items, sizeof(char*) * (len + 1),
		sizeof(char*) * (len));
	}
	return (items2);
}

int			string_list_insert(t_string_list *items, int index,
const char *item)
{
	char			*item2;
	char			**items2;
	int				len;

	len = items->length;
	if (index < 0)
		return (ERR_NEG_INDEX);
	index = (index > len) ? len : index;
	if ((item2 = ft_strdup(item)) == NULL)
		return (ERR_MEM_ALLOC_FAILED);
	items2 = string_list_items_malloc(items, len);
	if (items2 == NULL)
	{
		free(item2);
		return (ERR_MEM_ALLOC_FAILED);
	}
	if (index < len)
	{
		ft_memmove(&items2[index + 1],
		&items2[index], (len - index) * sizeof(items2[0]));
	}
	items2[index] = item2;
	items->length++;
	items->items = items2;
	return (NO_ERROR);
}
