/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:57:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 12:02:05 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "parser.h"
#include "utils.h"
#include "router.h"

void	make_conversions_padding(t_buffer *buffer, t_state *state, char c)
{
	state->conv_length = get_conv_length(state);
	if (ft_abs(state->padding) > state->conv_length)
	{
		if (state->padding < 0)
		{
			do_conv(buffer, state);
			state->padding += state->conv_length;
			make_padding(buffer, state, c);
		}
		else
		{
			state->padding -= state->conv_length;
			make_padding(buffer, state, c);
			do_conv(buffer, state);
		}
	}
	else
		do_conv(buffer, state);
}

void	make_int_zero_padding(t_buffer *buffer, t_state *state)
{
	int number;

	state->conv_length = get_conv_length(state);
	number = va_arg(state->args, int);
	if (state->padding > state->conv_length)
	{
		if (number < 0)
		{
			append_to_buffer(buffer, S_NEGATIVE);
			state->padding = state->padding - state->conv_length;
			make_padding(buffer, state, S_ZERO);
			if (number == INT_MIN)
				append_string_to_buffer(buffer, &INT_MIN_STR[1]);
			else
				itoa(buffer, -number);
		}
		else
		{
			state->padding = state->padding - state->conv_length;
			make_padding(buffer, state, S_ZERO);
			itoa(buffer, number);
		}
	}
	else
		itoa(buffer, number);
}

void	make_conversions_zero_padding(t_buffer *buffer, t_state *state)
{
	state->conv_length = get_conv_length(state);
	if (state->padding > state->conv_length)
	{
		state->padding = state->padding - state->conv_length;
		make_padding(buffer, state, S_ZERO);
		do_conv(buffer, state);
	}
	else
	{
		if (!ft_is_zero(state) || state->conv & C_HEX_LOWER ||
		state->conv & C_HEX_UPPER || state->conv & C_UNSIGNED)
			do_conv(buffer, state);
	}
}

void	make_padding(t_buffer *buffer, t_state *state, char c)
{
	int padding;

	padding = ft_abs(state->padding);
	while (padding-- > 0)
		append_to_buffer(buffer, c);
}
