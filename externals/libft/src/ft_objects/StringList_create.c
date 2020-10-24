/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringList_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 08:22:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/18 10:36:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_objects.h"
#include "ft_strings.h"

void	string_list_create(t_string_list **str_list)
{
	t_string_list *new;

	if ((new = malloc(sizeof(t_string_list))) == NULL)
		*str_list = NULL;
	else
	{
		new->length = 0;
		new->items = NULL;
		*str_list = new;
	}
}
