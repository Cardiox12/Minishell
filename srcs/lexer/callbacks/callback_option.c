/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:37:03 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 21:38:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		callback_option(t_lexer *lex)
{
	if (lex->input[lex->index] == '-' || (lex->input[lex->index] == '-' && lex->input[lex->index + 1] == '-'))
	{
		lex->index = get_option(&lex->head, lex->input, lex->index);
		return (TRUE);
	}
	return (FALSE);
}