/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:21:56 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/07 00:30:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "ft_math.h"
#include "ft_strings.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "eval.h"

t_vec		spair_length(t_spair pair)
{
	t_vec length;

	length.x = ft_strlen(pair.first);
	length.y = ft_strlen(pair.second);
	return (length);
}

t_spair		get_chunks(char *src, t_slice slice)
{
	t_spair chunks;

	chunks.first = ft_strndup(src, slice.begin);
	if (chunks.first == NULL)
		return ((t_spair){NULL, NULL});
	chunks.second = ft_strdup(src + slice.end);
	if (chunks.second == NULL)
	{
		free(chunks.first);
		return ((t_spair){NULL, NULL});
	}
	return (chunks);
}

static char	*substitute(char **src, t_slice slice, t_spair pair)
{
	t_spair chunks;
	size_t	size;
	char	*subs;

	chunks = get_chunks(*src, slice);
	size = ft_strlen(chunks.first) + ft_strlen(pair.second) +
	ft_strlen(chunks.second);
	subs = ft_strnew(sizeof(char) * size);
	if (subs == NULL)
	{
		free_spair(chunks);
		return (NULL);
	}
	ft_strlcat(subs, chunks.first, size + 1);
	ft_strlcat(subs, pair.second, size + 1);
	ft_strlcat(subs, chunks.second, size + 1);
	free(*src);
	*src = subs;
	free_spair(chunks);
	return (*src);
}

char		*str_replace(char **src, const char *key, const char *value)
{
	char			*found;
	char			*str;
	t_slice			slice;
	t_vec			sizes;
	int				offset;

	str = *src;
	sizes = spair_length((t_spair){(char*)key, (char*)value});
	offset = 0;
	while ((found = ft_strstr(str + offset, key)) != NULL)
	{
		slice.begin = found - str;
		slice.end = slice.begin + sizes.x;
		str = substitute(src, slice,
			(t_spair){
				(char*)key,
				(char*)value
		});
		offset = slice.begin + sizes.y;
	}
	return (*src);
}
