/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:04:26 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 00:09:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	commands(t_interpret *inter)
{
	int out;

	out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
	if (out != 0)
		return (out);
	while (is_type(inter->current->token.type, g_non_terminal_tokens,
	ARR_NON_TERM_SIZE))
	{
		if (inter->current->token.type == REDIRECTION)
		{
			out = eat(inter, (int[1]){REDIRECTION}, 1);
			if (out == _EOF_)
				return (SYNTAX_ERROR_NEWLINE);
			out = eat(inter, (int[1]){FILE_DESCRIPTOR}, 1);
			if (out != 0)
				return (out);
		}
		out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
		if (out != 0)
			return (out);
	}
	return (SUCCESS);
}
