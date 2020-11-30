/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:45:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/30 20:02:42 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "eval.h"
#include "ft_stdio.h"

static size_t	strlen_without_quotes(const char *input, int quote)
{
	size_t size;
	size_t index;

	index = 0;
	size = 0;
	while (input[index] != quote && input[index] != '\0')
	{
		if (is_escaped_by(&input[index], ESC_BASE_CHARSET))
		{
			size++;
			index++;
		}
		else
			size++;
		index++;
	}
	return (size);
}

static void		strcpy_without_quotes(char *dst, const char *src,
int quote, size_t *idx)
{
	size_t second;

	second = 0;
	while (src[*idx] != quote && src[*idx] != '\0')
	{
		if (is_escaped_by(&src[*idx], ESC_BASE_CHARSET))
		{
			dst[second++] = src[++(*idx)];
		}
		else if (is_escaped_by(&src[*idx], ESC_IMPROVED_CHARSET))
		{
			dst[second++] = src[(*idx)++];
			dst[second++] = src[(*idx)];
		}
		else
		{
			dst[second++] = src[*idx];
		}
		(*idx)++;
	}
	if (src[*idx] == quote)
		(*idx)++;
}

char			*remove_quotes(const char *input, size_t *index)
{
	const char		*str = &input[*index];
	size_t			size;
	char			*ret;

	size = strlen_without_quotes(&str[1], *str);
	ret = ft_strnew(size);
	if (ret == NULL)
		return (NULL);
	(*index)++;
	strcpy_without_quotes(ret, input, *str, index);
	return (ret);
}
