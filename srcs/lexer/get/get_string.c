/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:53:39 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 20:57:03 by bbellavi         ###   ########.fr       */
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
	content = quote_extract(input, &index);
	enqueue(head, (t_token){
		.type = type,
		.value = content,
		.index = previous
	});
	return (index);
}
