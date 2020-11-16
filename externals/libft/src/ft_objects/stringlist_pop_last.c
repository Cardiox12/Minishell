/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist_pop_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 03:43:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:39:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_objects.h"

int	string_list_pop_last(t_string_list *list)
{
	if (list->length != 0)
		return (string_list_pop(list, list->length - 1));
	return (NO_ERROR);
}
