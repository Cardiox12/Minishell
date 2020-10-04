/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 04:38:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:54:56 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	pass(t_state *state)
{
	if (state->conv & C_CHAR || state->conv & C_PERCENT)
		va_arg(state->args, int);
	else if (state->conv & C_STRING)
		va_arg(state->args, char*);
	else if (state->conv & C_POINTER)
		va_arg(state->args, void*);
	else if (state->conv & C_INTEGER)
		va_arg(state->args, int);
	else if (state->conv & C_UNSIGNED)
		va_arg(state->args, unsigned int);
	else if (state->conv & C_HEX_LOWER)
		va_arg(state->args, unsigned int);
	else if (state->conv & C_HEX_UPPER)
		va_arg(state->args, unsigned int);
}
