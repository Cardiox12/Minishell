/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:31:30 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:41:12 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

/*
** ---------------------------------------------------------------------------
**
**								Flush buffer
**
** Description : The flush_buffer function show the buffer then clean the buffer
** Param :buffer: the buffer to flush
** Returns :void: nothing
**
** ---------------------------------------------------------------------------
*/

void	flush_buffer(t_buffer *buffer)
{
	size_t index;

	index = 0;
	show_buffer(buffer);
	while (index < BUFFER_SIZE)
		buffer->buffer[index++] = 0;
}
