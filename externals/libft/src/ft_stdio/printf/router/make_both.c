/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:52:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:38 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"
#include "router.h"

static int	get_total_width(t_state *state)
{
	const int length = state->conv_length;

	ft_is_negative(state);
	if (state->specs & IS_ZERO && state->precision == 0 && state->conv &
	C_INTEGER)
		return (ft_abs(state->padding));
	if (state->specs & IS_ZERO)
		return (ft_abs(state->padding) - state->precision);
	if (state->specs & IS_NEGATIVE && state->conv & C_INTEGER)
	{
		if (state->precision < state->conv_length)
			return (ft_abs(state->padding) - state->conv_length);
		return (ft_abs(state->padding) - state->precision - 1);
	}
	if (state->precision == 0 || length > state->precision)
		return (ft_abs(state->padding) - state->conv_length);
	return (ft_abs(state->padding) - state->precision);
}

void		make_string_pp(t_buffer *buffer, t_state *state)
{
	const int padding = ft_abs(state->padding);

	state->conv_length = get_conv_length(state);
	if (padding > state->conv_length && state->precision > state->conv_length)
		state->precision = state->conv_length;
	if (state->precision >= 0 && padding > state->precision)
	{
		if (state->padding < 0)
		{
			make_string_precision(buffer, state);
			state->padding = ft_abs(state->padding) - state->precision;
			make_padding(buffer, state, S_SPACE);
		}
		else
		{
			state->padding = ft_abs(state->padding) - state->precision;
			make_padding(buffer, state, S_SPACE);
			make_string_precision(buffer, state);
		}
	}
	else
		make_string_precision(buffer, state);
}

void		make_int_pp(t_buffer *buffer, t_state *state)
{
	const int padding = ft_abs(state->padding);

	state->conv_length = get_conv_length(state);
	ft_is_zero(state);
	if (padding > state->precision)
	{
		if (state->padding < 0)
		{
			make_int_precision(buffer, state);
			state->padding = padding;
			state->padding = get_total_width(state);
			if (padding >= state->conv_length)
				make_padding(buffer, state, S_SPACE);
		}
		else
		{
			state->padding = get_total_width(state);
			if (padding >= state->conv_length)
				make_padding(buffer, state, S_SPACE);
			make_int_precision(buffer, state);
		}
	}
	else
		make_int_precision(buffer, state);
}

void		make_conversions_pp(t_buffer *buffer, t_state *state)
{
	const int padding = ft_abs(state->padding);

	state->conv_length = (state->precision == 0) ? 2 : get_conv_length(state);
	if (padding > state->precision && padding > state->conv_length)
	{
		ft_is_zero(state);
		if (state->padding < 0)
		{
			make_conversions_precision(buffer, state);
			state->padding = padding;
			state->padding = get_total_width(state);
			make_padding(buffer, state, S_SPACE);
		}
		else
		{
			state->padding = get_total_width(state);
			make_padding(buffer, state, S_SPACE);
			state->padding = get_total_width(state);
			make_conversions_precision(buffer, state);
		}
	}
	else
		make_conversions_precision(buffer, state);
}
