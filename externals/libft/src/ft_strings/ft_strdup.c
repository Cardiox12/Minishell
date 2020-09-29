/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:37:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:50 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strdup(const char *s1)
{
	char *duplicate;
	char *begin;

	duplicate = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (duplicate == NULL)
		return (NULL);
	begin = duplicate;
	while (*s1 != '\0')
		*duplicate++ = *s1++;
	*duplicate = '\0';
	return (begin);
}
