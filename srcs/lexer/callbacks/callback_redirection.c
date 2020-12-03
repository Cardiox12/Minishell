/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:44:40 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/03 10:35:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>
int		callback_redirection(t_lexer *lex)
{
	if (is_redirect(lex->input[lex->index]))
	{
		lex->index = get_redirection(&lex->head, lex->input, lex->index);
		if (lex->state == IS_COMMAND)
		{
			lex->state = IS_SHIFTED;
		}
		else
		{
			lex->state ^= IS_ARGUMENT;
		}
		lex->state |= IS_FD;
		return (TRUE);
	}
	return (FALSE);	
}
