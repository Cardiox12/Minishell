/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:55:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:50 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uchar_s = s;
	unsigned char		uchar_c;

	uchar_c = c;
	while (n-- > 0)
	{
		if (*uchar_s == uchar_c)
			return ((void*)uchar_s);
		uchar_s++;
	}
	return (NULL);
}
