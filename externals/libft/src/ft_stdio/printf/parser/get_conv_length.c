/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:06:03 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:17:57 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

static int		get_int_length(int number)
{
	int length;

	length = 0;
	if (number == INT_MIN)
		return (11);
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = -number;
		length++;
	}
	while (number > 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

static int		get_hex_length(unsigned int number)
{
	int length;

	length = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= HEX_BASE;
		length++;
	}
	return (length);
}

static int		get_uint_length(unsigned int number)
{
	int length;

	length = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

static int		get_pointer_length(long long addr)
{
	int length;

	length = 0;
	if (addr == 0)
		return (3);
	while (addr > 0)
	{
		addr /= HEX_BASE;
		length++;
	}
	return (length + 2);
}

int				get_conv_length(t_state *state)
{
	va_list	copy;
	char	*str;

	va_copy(copy, state->args);
	if (state->conv & C_CHAR || state->conv & C_PERCENT || state->conv == 0)
		return (1);
	else if (state->conv & C_STRING)
	{
		if ((str = va_arg(copy, char*)) != NULL)
			return (ft_strlen(str));
		return (NULL_LENGTH);
	}
	else if (state->conv & C_POINTER)
		return (get_pointer_length((long long)va_arg(copy, void*)));
	else if (state->conv & C_INTEGER)
		return (get_int_length(va_arg(copy, int)));
	else if (state->conv & C_UNSIGNED)
		return (get_uint_length(va_arg(copy, unsigned int)));
	else if (state->conv & C_HEX_LOWER || state->conv & C_HEX_UPPER)
		return (get_hex_length(va_arg(copy, unsigned int)));
	return (0);
}
