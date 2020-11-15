/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:43:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 22:07:42 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_stdio.h"

t_queue *lexer(const char *input)
{
	const size_t    length = ft_strlen(input);
	t_lexer			lex;
	size_t          index;

	lex = (t_lexer){.head = NULL, .index = 0, .state = IS_COMMAND, .input = (char*)input};
	while (lex.index < length)
	{
		index = 0;
		while (index < LEXER_CALLBACK_SIZE)
		{
			if (g_lexer_callbacks[index](&lex))
				break ;
			index++;
		}
	}
	return (lex.head);
}