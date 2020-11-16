/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:32:04 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 01:19:44 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		callback_command(t_lexer *lex)
{
	if (!is_sep(lex->input[lex->index]) && ft_isprint(lex->input[lex->index])
	&& lex->state & IS_COMMAND && !is_redirect(lex->input[lex->index]))
	{
		lex->index = get_command(&lex->head, lex->input, lex->index);
		lex->state ^= IS_COMMAND;
		lex->state |= IS_ARGUMENT;
		return (TRUE);
	}
	return (FALSE);
}
