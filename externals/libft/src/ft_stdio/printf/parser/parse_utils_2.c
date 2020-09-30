/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:35:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:52:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "router.h"
#include "utils.h"

void	route_precision_padding(t_buffer *buffer, t_state *state)
{
	if (state->conv & C_STRING)
		make_string_pp(buffer, state);
	else if (state->conv & C_INTEGER)
		make_int_pp(buffer, state);
	else if (state->conv & C_PERCENT)
		make_conversions_padding(buffer, state, (state->flags & F_ZERO)
		? S_ZERO : S_SPACE);
	else
		make_conversions_pp(buffer, state);
}

void	route_precision(t_buffer *buffer, t_state *state)
{
	if (state->conv & C_STRING)
		make_string_precision(buffer, state);
	else if (state->conv & C_INTEGER)
		make_int_precision(buffer, state);
	else if (state->conv != 0 && !(state->conv & C_PERCENT))
		make_conversions_precision(buffer, state);
	else if (state->conv & C_PERCENT)
		do_conv(buffer, state);
}

void	route_padding(t_buffer *buffer, t_state *state)
{
	if (state->padding < 0)
		make_conversions_padding(buffer, state, S_SPACE);
	else if (state->conv & C_INTEGER)
		make_int_zero_padding(buffer, state);
	else
		make_conversions_zero_padding(buffer, state);
}
