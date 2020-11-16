/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 04:43:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:49:33 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strcharset(const char *s, const char *charset)
{
	size_t index;

	while (*s != '\0')
	{
		index = 0;
		while (charset[index] != '\0')
		{
			if (charset[index] == *s)
				return ((char*)s);
			index++;
		}
		s++;
	}
	return (NULL);
}
