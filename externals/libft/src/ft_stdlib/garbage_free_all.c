/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_free_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 05:24:40 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:58:42 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

/*
**	Garbage_free_all
**
**	Free every node and references of the current garbage.
*/

void	garbage_free_all(void)
{
	t_ref_list *cur;
	t_ref_list *old;

	if (g_garbage.refs != NULL)
	{
		cur = g_garbage.refs;
		while (cur != NULL)
		{
			old = cur;
			cur = cur->next;
			if (old->ref != NULL)
				free(old->ref);
			if (old != NULL)
				free(old);
		}
	}
}
