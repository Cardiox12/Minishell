/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:40:16 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 01:20:12 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		callback_pipe(t_lexer *lex)
{
	if (lex->input[lex->index] == SYM_PIPE)
	{
		lex->index = get_pipe(&lex->head, lex->index);
		lex->state ^= IS_COMMAND;
		return (TRUE);
	}
	return (FALSE);
}
