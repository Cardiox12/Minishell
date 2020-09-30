/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:18:12 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:56:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "parser.h"

void	itoa(t_buffer *buffer, int number)
{
	if (number == INT_MIN)
		append_string_to_buffer(buffer, INT_MIN_STR);
	else
	{
		if (number < 0)
		{
			append_to_buffer(buffer, '-');
			number = -number;
			itoa(buffer, number);
		}
		else if (number >= 10)
		{
			itoa(buffer, number / 10);
			append_to_buffer(buffer, number % 10 + '0');
		}
		else
			append_to_buffer(buffer, number % 10 + '0');
	}
}
