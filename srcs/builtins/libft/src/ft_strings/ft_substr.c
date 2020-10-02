/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:35:31 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:50 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (start + len > ft_strlen(s))
		len = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	sub[len] = '\0';
	return (ft_memcpy(sub, s + start, len));
}
