/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringList_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:38:18 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/18 10:49:20 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

void	string_list_iter(t_string_list *list, int (*f)(const char*))
{
	int index;

	index = 0;
	while (index < list->length)
	{
		f(list->items[index]);
		index++;
	}
}