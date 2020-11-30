/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:21:56 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/30 23:36:46 by bbellavi         ###   ########.fr       */
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

t_spair		get_chunks(char *src, char *tok, t_spair pair)
{
	t_spair chunks;
	t_vec	lengths;
	size_t	src_len;
	size_t	beg_index;

	lengths = spair_length(pair);
	src_len = ft_strlen(src);
	beg_index = tok - src;
	chunks.first = ft_substr(src, 0, beg_index);
	chunks.second = ft_substr(
		src,
		beg_index + lengths.x, src_len - (beg_index + lengths.x));
	return (chunks);
}

static char	*substitute(char **src, char *tok, t_spair pair)
{
	t_spair chunks;
	size_t	size;
	char	*str;

	chunks = get_chunks(*src, tok, pair);
	if (chunks.first == NULL || chunks.second == NULL)
		free_spair(chunks);
	size = ft_strlen(chunks.first) + ft_strlen(pair.second)
	+ ft_strlen(chunks.second) + 1;
	str = ft_strnew(size);
	if (str == NULL)
	{
		free_spair(chunks);
		return (NULL);
	}
	ft_strlcat(str, chunks.first, size + 1);
	ft_strlcat(str, pair.second, size + 1);
	ft_strlcat(str, chunks.second, size + 1);
	free(*src);
	*src = str;
	free_spair(chunks);
	return (*src);
}

char		*str_replace(char **src, const char *key, const char *value)
{
	char	*tok;
	char	*str;
	size_t	srclen;

	str = *src;
	srclen = ft_strlen(str);
	while ((tok = ft_strnstr(str, key, srclen)) != NULL)
	{
		substitute(src, tok, (t_spair){(char*)key, (char*)value});
	}
	return (*src);
}
