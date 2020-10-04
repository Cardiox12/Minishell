/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:36:08 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:50 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strrchr(const char *s, int c)
{
	char *c_s;
	char *acc;
	char char_c;

	c_s = (char*)s;
	char_c = c;
	acc = NULL;
	while (*c_s)
	{
		if (*c_s == char_c)
			acc = c_s;
		c_s++;
	}
	if (*c_s == char_c)
		acc = c_s;
	return (acc);
}
