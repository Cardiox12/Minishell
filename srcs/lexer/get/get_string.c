/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:53:39 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 00:41:12 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "expand.h"
#include "ft_strings.h"
#include "ft_stdlib.h"

static char	*join(char **content, const char *input, size_t *index)
{
	char	*next;
	int		escape_mode;

	while (ft_isquote(input[*index]))
	{
		escape_mode = input[*index] == SYM_SIMPLE_QUOTE;
		if (!is_quote_closed(&input[*index + 1], input[*index]))
		{
			free(*content);
			return (NULL);
		}
		next = remove_quotes(input, index);
		if (!escape_mode)
			next = str_expand(&next, STRING);
		strjoin(content, next);
		free(next);
	}
	return (*content);
}

int			get_string(t_queue **head, const char *input, size_t index)
{
	size_t	previous;
	int		type;
	char	*content;

	previous = index;
	content = NULL;
	type = (input[index] == SYM_QUOTE) ? STRING : RAW_STRING;
	if (!is_quote_closed(&input[index + 1], input[index]))
		return (index);
	content = remove_quotes(input, &index);
	if (type == STRING)
		content = str_expand(&content, type);
	if (ft_isquote(input[index]))
	{
		type = STRING;
		if (join(&content, input, &index) == NULL)
			return (index);
	}
	enqueue(head, (t_token){
		.type = type,
		.value = content,
		.index = previous,
		.prefixed = is_bash_charset(input[index])
	});
	return (index);
}
