/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_active.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 01:48:29 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:56:05 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	state_has_active_flag(t_state *state)
{
	return (state->flags & F_NEGATIVE ||
			state->flags & F_ZERO ||
			state->flags & F_PRECISION ||
			state->flags & F_ASTERISK);
}
