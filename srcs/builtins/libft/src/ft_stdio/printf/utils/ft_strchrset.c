/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 02:09:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 12:18:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strchrset(const char *s, const char *charset)
{
	size_t index;

	index = 0;
	while (*s)
	{
		while (charset[index] != '\0')
		{
			if (charset[index] == *s)
				return ((char*)s);
			index++;
		}
		s++;
		index = 0;
	}
	return (NULL);
}
