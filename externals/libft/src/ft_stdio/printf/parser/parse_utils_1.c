/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:49:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:50:56 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "router.h"
#include "utils.h"

static char	*get_padding(t_state *state, char *fmt)
{
	if (ft_isdigit(*fmt))
	{
		state->padding = (state->flags & F_NEGATIVE) ? -ft_atoi(fmt) :
		ft_atoi(fmt);
		while (ft_isdigit(*fmt) && *fmt != '\0')
			fmt++;
	}
	else if (*fmt == S_ASTERISK)
	{
		state->padding = va_arg(state->args, int);
		if (state->padding > 0 && state->flags & F_NEGATIVE)
		{
			state->padding = -state->padding;
			state->flags ^= F_NEGATIVE;
		}
		fmt++;
	}
	return (fmt);
}

static char	*get_precision(t_state *state, char *fmt)
{
	if (ft_isdigit(*fmt))
	{
		state->precision = ft_atoi(fmt);
		while (ft_isdigit(*fmt) && *fmt != '\0')
			fmt++;
	}
	else if (*fmt == S_ASTERISK)
	{
		state->precision = va_arg(state->args, int);
		if (state->precision > 0 && state->flags & F_NEGATIVE)
		{
			state->precision = -state->precision;
			state->flags ^= F_NEGATIVE;
		}
		fmt++;
	}
	return (fmt);
}

static char	*get_flags(t_state *state, char *fmt)
{
	while (ft_strchr(CONVERSIONS, *fmt) == NULL && *fmt != '\0')
	{
		set_flags(state, *fmt);
		if ((ft_isdigit(*fmt) || *fmt == S_ASTERISK) &&
		!(state->flags & F_PRECISION))
			fmt = get_padding(state, fmt);
		else if ((ft_isdigit(*fmt) || *fmt == S_ASTERISK) &&
		state->flags & F_PRECISION)
			fmt = get_precision(state, fmt);
		else if (ft_strchr(ALL_SYMBOLS, *fmt) != NULL)
		{
			fmt++;
			if (state->flags & F_PRECISION && *fmt == S_ZERO)
				fmt++;
		}
		else
			break ;
	}
	return (fmt);
}

char		*get_state(t_state *state, const char *s)
{
	char *fmt;

	fmt = (char*)s;
	fmt = get_flags(state, fmt);
	if (state->flags & F_ZERO && state->flags & F_NEGATIVE)
		state->flags = state->flags ^ F_ZERO;
	if (ft_strchr(CONVERSIONS, *fmt))
		set_conv(state, *fmt++);
	if (state->precision < 0)
		state->flags ^= F_PRECISION;
	return (fmt);
}

void		route_flag(t_buffer *buffer, t_state *state)
{
	if (state->conv == 0)
	{
		if (state->padding > 0)
			make_padding(buffer, state, S_SPACE);
	}
	else if (state->flags & F_PRECISION && state->padding != 0)
		route_precision_padding(buffer, state);
	else if (state->flags & F_PRECISION)
		route_precision(buffer, state);
	else if (state->flags & F_ZERO)
		route_padding(buffer, state);
	else if (state->padding != 0)
		make_conversions_padding(buffer, state, S_SPACE);
	else
		do_conv(buffer, state);
}
