/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itohl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:36:02 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:57:28 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "parser.h"

void	itohl(t_buffer *buffer, unsigned int number)
{
	if (number >= HEX_BASE)
	{
		itohl(buffer, number / HEX_BASE);
		append_to_buffer(buffer, HEX_LOWER_BASE[number % HEX_BASE]);
	}
	else
		append_to_buffer(buffer, HEX_LOWER_BASE[number % HEX_BASE]);
}
