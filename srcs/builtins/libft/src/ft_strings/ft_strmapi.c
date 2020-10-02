/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:36:42 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:50 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const size_t	size = ft_strlen(s);
	size_t			index;
	char			*mapped;

	mapped = malloc(sizeof(char) * (size + 1));
	if (mapped == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		mapped[index] = f(index, s[index]);
		index++;
	}
	mapped[index] = '\0';
	return (mapped);
}
