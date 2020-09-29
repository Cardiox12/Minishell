/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:39:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:50 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*begin;
	unsigned char	*s_b;
	char			uchar_c;

	uchar_c = c;
	s_b = b;
	begin = s_b;
	while (len-- > 0)
		*s_b++ = uchar_c;
	return (begin);
}
