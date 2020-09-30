/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:25:45 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:54:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "router.h"
#include "buffer.h"

static void	route(t_buffer *buffer, t_state *state)
{
	if (state_has_active_flag(state) || state->padding != 0)
		route_flag(buffer, state);
	else
		do_conv(buffer, state);
}

static int	state_unintialized(t_state *state)
{
	return (
	state->flags == 0 &&
	state->conv == 0 &&
	state->precision == 0 &&
	state->padding == 0);
}

char		*ft_parse(t_buffer *buffer, t_state *state, const char *s)
{
	char *fmt;

	init_state(state);
	fmt = "";
	if (*s != '\0')
	{
		fmt = get_state(state, s);
		if (!state_unintialized(state))
			route(buffer, state);
	}
	init_state(state);
	return (fmt);
}
