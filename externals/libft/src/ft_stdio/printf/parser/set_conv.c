/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 02:03:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:55:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_conv(t_state *state, const char c)
{
	if (c == S_CHAR)
		state->conv |= C_CHAR;
	else if (c == S_STRING)
		state->conv |= C_STRING;
	else if (c == S_POINTER)
		state->conv |= C_POINTER;
	else if (c == S_INTEGER || c == S_DOUBLE)
		state->conv |= C_INTEGER;
	else if (c == S_UNSIGNED)
		state->conv |= C_UNSIGNED;
	else if (c == S_HEX_LOWER)
		state->conv |= C_HEX_LOWER;
	else if (c == S_HEX_UPPER)
		state->conv |= C_HEX_UPPER;
	else if (c == S_PERCENT)
		state->conv |= C_PERCENT;
}
