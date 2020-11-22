/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:43:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/22 23:49:55 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_stdio.h"

static void	skip(t_lexer *lex)
{
	while (ft_isspace(lex->input[lex->index]) && lex->input[lex->index] != '\0')
		lex->index++;
}

t_queue	*lexer(const char *input)
{
	const size_t	length = ft_strlen(input);
	t_lexer			lex;
	size_t			index;

	lex = (t_lexer){
		.head = NULL,
		.index = 0,
		.state = IS_COMMAND,
		.input = (char*)input
	};
	while (lex.index < length)
	{
		index = 0;
		while (index < LEXER_CALLBACK_SIZE)
		{
			if (g_lexer_callbacks[index](&lex))
				break ;
			index++;
		}
		if (g_quote_parity_error)
			return (lex.head);
		skip(&lex);
	}
	return (lex.head);
}
