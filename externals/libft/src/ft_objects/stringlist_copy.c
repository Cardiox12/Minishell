/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:40:17 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:40:04 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_objects.h"

void	string_list_copy(t_string_list **dst, t_string_list *src)
{
	size_t index;

	string_list_create(dst);
	if (*dst == NULL)
		return ;
	index = 0;
	while (index < src->length)
	{
		string_list_append(*dst, src->items[index]);
		index++;
	}
}
