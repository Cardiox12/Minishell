/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 06:04:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/09 06:09:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_strings.h"

/*
**	ft_realloc
**
**	Alloc new size, make copy of p into new memory allocation and free old
**	pointer.
*/

void	*ft_realloc(void *p, size_t new_size, size_t old_size)
{
	void *new;

	if (p == NULL)
		return (NULL);
	if ((new = malloc(new_size)) == NULL)
		return (NULL);
	ft_bzero(new, new_size);
	if (new_size < old_size)
		ft_memcpy(new, p, new_size);
	else
		ft_memcpy(new, p, old_size);
	free(p);
	return (new);
}
