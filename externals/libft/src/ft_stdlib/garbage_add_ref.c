/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_add_ref.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 05:21:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:59:05 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

/*
**	Garbage_add_ref
**
**	Add reference passed in parameter.
**	It allocate and add new Ref_List node to the current garbage.
*/

t_garbage g_garbage = (t_garbage){0, NULL};

t_ref_list	*garbage_add_ref(void *p)
{
	t_ref_list *cur;
	t_ref_list *tmp;

	tmp = malloc(sizeof(t_garbage));
	if (tmp == NULL)
		return (NULL);
	g_garbage.length++;
	tmp->ref = p;
	if (g_garbage.refs == NULL)
	{
		tmp->next = NULL;
		g_garbage.refs = tmp;
	}
	else
	{
		cur = g_garbage.refs;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = tmp;
	}
	return (tmp);
}
