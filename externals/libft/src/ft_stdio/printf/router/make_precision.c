/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:29:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:24 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "router.h"
#include "utils.h"

static void	make_negative_int_precision(t_buffer *buffer, t_state *state, int n)
{
	state->padding = state->precision - state->conv_length;
	make_padding(buffer, state, S_ZERO);
	itoa(buffer, n);
}

void		make_int_precision(t_buffer *buffer, t_state *state)
{
	int number;

	state->conv_length = get_conv_length(state);
	number = va_arg(state->args, int);
	if (number == 0 && state->precision == 0)
		return ;
	if (state->precision >= state->conv_length)
	{
		if (number < 0)
		{
			state->specs |= IS_NEGATIVE;
			append_to_buffer(buffer, S_NEGATIVE);
			state->padding = state->precision - state->conv_length + 1;
			make_padding(buffer, state, S_ZERO);
			if (number == INT_MIN)
				append_string_to_buffer(buffer, &INT_MIN_STR[1]);
			else
				itoa(buffer, -number);
		}
		else
			make_negative_int_precision(buffer, state, number);
	}
	else
		itoa(buffer, number);
}

void		make_string_precision(t_buffer *buffer, t_state *state)
{
	char *string;

	string = va_arg(state->args, char*);
	if (string == NULL)
		string = NULL_MESSAGE;
	if (state->precision < (int)ft_strlen(string))
		append_nchar_to_buffer(buffer, string, state->precision);
	else
		append_string_to_buffer(buffer, string);
}

void		make_conversions_precision(t_buffer *buffer, t_state *state)
{
	state->conv_length = get_conv_length(state);
	if (state->precision > state->conv_length)
	{
		state->padding = state->precision - state->conv_length;
		make_padding(buffer, state, S_ZERO);
		do_conv(buffer, state);
	}
	else
	{
		if (!ft_is_zero(state) || state->precision != 0)
			do_conv(buffer, state);
		else
			pass(state);
	}
}
