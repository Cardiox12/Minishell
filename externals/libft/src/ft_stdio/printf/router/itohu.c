/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itohu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:14:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:57:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "parser.h"

void	itohu(t_buffer *buffer, unsigned int number)
{
	if (number >= HEX_BASE)
	{
		itohu(buffer, number / HEX_BASE);
		append_to_buffer(buffer, HEX_UPPER_BASE[number % HEX_BASE]);
	}
	else
		append_to_buffer(buffer, HEX_UPPER_BASE[number % HEX_BASE]);
}
