/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:04:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 23:39:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	terminals(t_interpret *inter)
{
	int	out;

	if (is_type(inter->current->token.type, g_terminal_tokens, ARR_TERM_SIZE))
	{
		out = eat(inter, g_terminal_tokens, ARR_TERM_SIZE);
		if (out != 0)
			return ((out < 0) ? SUCCESS : out);
	}
	return (SUCCESS);
}
