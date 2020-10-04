/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:04:54 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 17:53:07 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_is_zero(t_state *state)
{
	va_list	copy;

	va_copy(copy, state->args);
	if (state->conv & C_INTEGER || state->conv & C_UNSIGNED ||
	state->conv & C_HEX_LOWER || state->conv & C_HEX_UPPER)
	{
		if (va_arg(copy, int) == 0)
		{
			state->specs |= IS_ZERO;
			return (1);
		}
	}
	return (0);
}
