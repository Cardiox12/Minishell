/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_find_ref.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 06:22:28 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/09 06:25:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

/*
**	Garbage_find_ref
**
**	Find reference and return pointer to the node of the current garbage
**	containing the reference.
**	If no reference is found, Garbage_find_ref returns NULL pointer.
*/

t_Ref_List	*garbage_find_ref(void *p)
{
	t_Ref_List *cur;

	if (g_garbage.refs != NULL)
	{
		cur = g_garbage.refs;
		while (cur != NULL)
		{
			if (cur->ref == p)
				return (cur);
			cur = cur->next;
		}
	}
	return (NULL);
}
