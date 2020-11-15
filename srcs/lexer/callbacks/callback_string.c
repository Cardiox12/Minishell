/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:36:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 21:36:45 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		callback_string(t_lexer *lex)
{
	if (lex->input[lex->index] == '"' || lex->input[lex->index] == '\'')
	{
		lex->index = get_string(&lex->head, lex->input, lex->index);
		return (TRUE);
	}
	return (FALSE);
}