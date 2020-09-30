/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:38:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:24:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_state(t_state *state)
{
	if (state != NULL)
	{
		state->flags = 0;
		state->conv = 0;
		state->padding = 0;
		state->precision = 0;
		state->conv_length = 0;
		state->specs = 0;
	}
}
