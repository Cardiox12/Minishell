/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:00:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:41:11 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_objects.h"
#include "ft_strings.h"
#include "ft_stdlib.h"

int	string_list_pop(t_string_list *list, int index)
{
	const int	len = list->length;
	char		**ptr;

	if (index < 0)
		return (ERR_NEG_INDEX);
	if (index > len)
		return (ERR_INDEX_OUT_OF_RANGE);
	if (list->items[index] != NULL)
		free(list->items[index]);
	ft_memmove(&list->items[index], &list->items[index + 1],
	(len - index) * sizeof(char*));
	ptr = ft_realloc(list->items, sizeof(char*) * (len - 1),
	sizeof(char*) * (len - 1));
	if (ptr == NULL)
		return (ERR_MEM_ALLOC_FAILED);
	list->length--;
	list->items = ptr;
	return (NO_ERROR);
}
