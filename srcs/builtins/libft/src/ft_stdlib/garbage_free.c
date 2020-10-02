/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 05:23:42 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/09 05:43:27 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

/*
**	Garbage_free
**
**	Find reference list node and free the reference passed in parameter
**	of the current garbage.
*/

void	garbage_free(void *p)
{
	t_Ref_List *cur;

	if (g_garbage.refs != NULL)
	{
		cur = g_garbage.refs;
		while (cur != NULL)
		{
			if (cur->ref == p)
			{
				free(cur->ref);
				cur->ref = NULL;
				break ;
			}
			cur = cur->next;
		}
	}
}
