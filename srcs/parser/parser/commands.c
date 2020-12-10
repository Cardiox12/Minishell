/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:04:26 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 01:30:13 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_redirection(t_interpret *inter)
{
	int out;

	if (inter->current == NULL)
		return (_EOF_);
	if (inter->current->token.type == REDIRECTION)
	{
		out = eat(inter, (int[1]){REDIRECTION}, 1);
		if (out == _EOF_)
			return (SYNTAX_ERROR_NEWLINE);
	}
	return (SUCCESS);
}

int			commands(t_interpret *inter)
{
	int out;

	out = check_redirection(inter);
	if (out != 0)
		return (out);
	out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
	if (out != 0)
		return (out);
	while (is_type(inter->current->token.type, g_non_terminal_tokens,
	ARR_NON_TERM_SIZE))
	{
		out = check_redirection(inter);
		if (out != 0)
			return (out);
		out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
		if (out != 0)
			return (out);
	}
	return (SUCCESS);
}
