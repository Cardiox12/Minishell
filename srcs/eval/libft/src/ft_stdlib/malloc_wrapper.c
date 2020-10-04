/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_wrapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 05:25:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/09 05:45:56 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

/*
**	Malloc_wrapper
**
**	Call malloc (3) and add the reference to the current garbage.
*/

void	*malloc_wrapper(size_t size)
{
	void *p;

	if ((p = malloc(size)) == NULL)
		return (NULL);
	if (garbage_add_ref(p) == NULL)
	{
		free(p);
		return (NULL);
	}
	return (p);
}
