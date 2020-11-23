/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:55:02 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 12:11:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_command(t_queue **head, const char *input, size_t index)
{
	const size_t	previous = index;
	char			*content;

	if (ft_isquote(input[index]))
	{
		if (!is_quote_closed(&input[index + 1], input[index]))
			return (index);
		content = remove_quotes(input, &index);
	}
	else
	{
		while (input[index] != '\0' && !is_sep(input[index]))
			index++;
		content = ft_strndup(&input[previous], index - previous);
	}
	enqueue(head, (t_token){
		.type = COMMAND,
		.value = content,
		.index = previous
	});
	return (index);
}
