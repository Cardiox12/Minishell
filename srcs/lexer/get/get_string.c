/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:53:39 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/22 20:37:47 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_string(t_queue **head, const char *input, size_t index)
{
	size_t	previous;
	int		type;
	char	*content;

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
	enqueue(head, (t_token){
		.type = type,
		.value = content,
		.index = previous
	});
	return (index);
}
