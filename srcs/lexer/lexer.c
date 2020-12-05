/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:43:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/05 08:57:16 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_stdio.h"

static void	skip(t_lexer *lex)
{
	while (ft_isspace(lex->input[lex->index]) && lex->input[lex->index] != '\0')
		lex->index++;
}

t_queue		*get_tokens(const char *input)
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

t_queue		*get_next_tokens(t_lexer *lexer)
{
	const size_t	length = ft_strlen(lexer->input);
	t_queue			*last;
	size_t			index;

	while (lexer->index < length)
	{
		index = 0;
		while (index < LEXER_CALLBACK_SIZE)
		{
			if (g_lexer_callbacks[index](lexer))
				break ;
			index++;
		}
		last = queue_last(lexer->head);
		if (last != NULL)
		{
			if (last->token.type == OPERATOR)
			{
				last = queue_pop_last(lexer->head);
				queue_free(last);
				return (lexer->head);
			}
		}
		skip(lexer);
	}
	return (lexer->head);
}
