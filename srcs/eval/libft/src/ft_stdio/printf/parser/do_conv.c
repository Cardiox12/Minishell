/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:50:26 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:51:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "router.h"

static void	do_conv_externals(t_buffer *buffer, t_state *state)
{
	char *str;

	if (state->conv & C_CHAR)
		append_to_buffer(buffer, va_arg(state->args, int));
	else if (state->conv & C_STRING)
	{
		if ((str = va_arg(state->args, char*)) != NULL)
			append_string_to_buffer(buffer, str);
		else
			append_string_to_buffer(buffer, NULL_MESSAGE);
	}
	else if (state->conv & C_POINTER)
	{
		if (state->flags & F_PRECISION && state->precision == 0)
			append_string_to_buffer(buffer, POINTER_PREFIX);
		else
			ptoa(buffer, (long long)va_arg(state->args, void*));
	}
}

void		do_conv(t_buffer *buffer, t_state *state)
{
	do_conv_externals(buffer, state);
	if (state->conv & C_INTEGER)
		itoa(buffer, va_arg(state->args, int));
	else if (state->conv & C_UNSIGNED)
		utoa(buffer, va_arg(state->args, unsigned int));
	else if (state->conv & C_HEX_LOWER)
		itohl(buffer, va_arg(state->args, unsigned int));
	else if (state->conv & C_HEX_UPPER)
		itohu(buffer, va_arg(state->args, unsigned int));
	else if (state->conv & C_PERCENT)
		append_to_buffer(buffer, S_PERCENT);
}
