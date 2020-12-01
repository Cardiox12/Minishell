/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:53:39 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/01 20:40:50 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "expand.h"
#include "ft_strings.h"
#include "ft_stdlib.h"
#include <stdio.h>

char		*strjoin(char **dst, const char *src)
{
	size_t size;
	size_t dstsize;

	if (*dst == NULL)
		*dst = ft_strdup(src);
	else
	{
		dstsize = ft_strlen(*dst);
		size = dstsize + ft_strlen(src);
		*dst = ft_realloc(*dst, sizeof(char) * (size + 1), sizeof(char) * (dstsize + 1));
		if (*dst == NULL)
			return (NULL);
		ft_strlcat(*dst, src, size + 1);
		(*dst)[size] = '\0';
	}
	return (*dst);
}

static char	*escape(char **content)
{
	str_replace(content, "\\", "\\\\");
	str_replace(content, "$", "\\$");

	return (*content);
}

int	get_string(t_queue **head, const char *input, size_t index)
{
	size_t	previous;
	int		type;
	char	*content = NULL;
	char	*next;

	previous = index;
	if (input[index] == SYM_SIMPLE_QUOTE)
	{
		type = RAW_STRING;
	}
	else
	{
		type = STRING;
	}
	if (!is_quote_closed(&input[index + 1], input[index]))
		return (index);
	content = remove_quotes(input, &index);
	while (ft_isquote(input[index]))
	{
		int escape_mode = input[index] == SYM_SIMPLE_QUOTE;
		next = remove_quotes(input, &index);
		if (escape_mode)
			escape(&next);
		strjoin(&content, next);
		free(next);
	}
	enqueue(head, (t_token){
		.type = type,
		.value = content,
		.index = previous
	});
	return (index);
}