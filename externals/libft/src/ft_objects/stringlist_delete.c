/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:14:30 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:40:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_objects.h"

void	string_list_delete(t_string_list **list)
{
	t_string_list	*ptr;
	size_t			index;
	char			*item;

	index = 0;
	ptr = *list;
	while (index < ptr->length)
	{
		item = ptr->items[index];
		free(item);
		index++;
	}
	free(ptr->items);
	free(ptr);
	*list = NULL;
}
