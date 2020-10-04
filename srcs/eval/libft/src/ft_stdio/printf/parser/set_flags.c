/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:54:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:56:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_flags(t_state *state, unsigned char c)
{
	if (c == S_NEGATIVE)
		state->flags |= F_NEGATIVE;
	else if (c == S_ZERO)
		state->flags |= F_ZERO;
	else if (c == S_PRECISION)
		state->flags |= F_PRECISION;
	else if (c == S_ASTERISK)
		state->flags |= F_ASTERISK;
}
