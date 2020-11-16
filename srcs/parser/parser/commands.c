/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:04:26 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:12:33 by bbellavi         ###   ########.fr       */
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
		out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
		if (out != 0)
			return (out);
	}
	return (SUCCESS);
}
