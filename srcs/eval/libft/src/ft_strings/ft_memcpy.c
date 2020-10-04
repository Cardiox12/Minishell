/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:39:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:50 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int index;

	index = 0;
	if (dst == src)
		return (NULL);
	while (n-- != 0)
	{
		((char*)dst)[index] = ((char*)src)[index];
		index++;
	}
	return (dst);
}
