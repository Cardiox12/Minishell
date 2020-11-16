/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist_to_string_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:35:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:40:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_objects.h"

char	**string_list_to_string_array(t_string_list *list)
{
	t_string_list	*copy;
	char			**items;
	size_t			last;

	string_list_copy(&copy, list);
	string_list_append(copy, "");
	items = copy->items;
	last = (copy->length == 0) ? 0 : copy->length - 1;
	free(copy);
	free(items[last]);
	items[last] = NULL;
	return (items);
}
