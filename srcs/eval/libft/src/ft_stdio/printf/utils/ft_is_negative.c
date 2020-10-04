/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:18:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 12:19:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		ft_is_negative(t_state *state)
{
	va_list copy;

	va_copy(copy, state->args);
	if (va_arg(copy, int) < 0)
	{
		state->specs |= IS_NEGATIVE;
		return (1);
	}
	return (0);
}
