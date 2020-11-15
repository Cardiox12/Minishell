/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:42:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 21:43:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		callback_operator(t_lexer *lex)
{
	if (lex->input[lex->index] == SYM_OPERATOR)
	{
		lex->index = get_operator(&lex->head, lex->index);
		lex->state ^= IS_COMMAND;
		lex->state ^= IS_ARGUMENT;
		return (TRUE);
	}
	return (FALSE);
}