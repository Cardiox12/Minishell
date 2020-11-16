/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:35:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 01:20:39 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		callback_fd(t_lexer *lex)
{
	if (lex->state & IS_FD && !ft_isspace(lex->input[lex->index]))
	{
		lex->index = get_fd(&lex->head, lex->input, lex->index);
		lex->state ^= IS_FD;
		return (TRUE);
	}
	return (FALSE);
}
