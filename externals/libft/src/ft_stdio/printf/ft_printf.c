/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 05:05:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:09:15 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"
#include "parser.h"
#include "buffer.h"

int		ft_printf(const char *fmt, ...)
{
	char		*s;
	t_buffer	buffer;
	t_state		state;

	init_buffer(&buffer);
	init_state(&state);
	va_start(state.args, fmt);
	s = (char*)fmt;
	while (*s)
	{
		if (*s == S_PERCENT)
		{
			++s;
			if (ft_issymbol(*s))
				s = ft_parse(&buffer, &state, s);
		}
		else
			append_to_buffer(&buffer, *s++);
	}
	show_buffer(&buffer);
	va_end(state.args);
	return (buffer.accumulator);
}
