/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:34:47 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 00:42:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "lexer.h"

char	*strjoin(char **dst, const char *src)
{
	size_t size;
	size_t dstsize;

	if (*dst == NULL)
		*dst = ft_strdup(src);
	else
	{
		dstsize = ft_strlen(*dst);
		size = dstsize + ft_strlen(src);
		*dst = ft_realloc(*dst, sizeof(char) * (size + 1), sizeof(char)
		* (dstsize + 1));
		if (*dst == NULL)
			return (NULL);
		ft_strlcat(*dst, src, size + 1);
		(*dst)[size] = '\0';
	}
	return (*dst);
}
