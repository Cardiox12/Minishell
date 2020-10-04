/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_wrapper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 06:09:38 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/09 06:26:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_strings.h"

/*
**	realloc_wrapper
**
**	Alloc new size, make copy of p into new memory allocation and free old
**	pointer and add the new reference to the current garbage.
*/

void	*realloc_wrapper(void *p, size_t new_size, size_t old_size)
{
	void *new;
	void *old;

	if (p == NULL)
		return (NULL);
	old = p;
	if ((new = malloc(new_size)) == NULL)
		return (NULL);
	if (new_size < old_size)
		ft_memcpy(new, p, new_size);
	else
		ft_memcpy(new, p, old_size);
	garbage_update_ref(p, new);
	free(old);
	return (new);
}
