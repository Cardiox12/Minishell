/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:37:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/10 02:15:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strdup(const char *s1)
{
	const size_t	size = ft_strlen(s1);
	char			*duplicate;

	duplicate = malloc(sizeof(char) * (size + 1));
	if (duplicate == NULL)
		return (NULL);
	ft_strcpy(duplicate, s1);
	duplicate[size] = '\0';
	return (duplicate);
}
