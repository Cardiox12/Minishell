/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:23:04 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 01:20:02 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		callback_argument(t_lexer *lex)
{
	if (is_bash_charset(lex->input[lex->index]) && lex->state & IS_ARGUMENT)
	{
		lex->index = get_argument(&lex->head, lex->input, lex->index);
		return (TRUE);
	}
	return (FALSE);
}
