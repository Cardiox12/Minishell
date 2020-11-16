/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 08:04:32 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:48:12 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strndup(const char *s, size_t n)
{
	const size_t	len = ft_strlen(s);
	char			*dup;

	if (n >= len)
		n = len;
	dup = malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	ft_strncpy(dup, s, n);
	dup[n] = '\0';
	return (dup);
}
