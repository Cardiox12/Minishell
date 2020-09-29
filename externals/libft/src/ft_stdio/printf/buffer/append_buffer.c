/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:44:01 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:36:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "utils.h"

/*
** ---------------------------------------------------------------------------
**
**								Append buffer
**
** Description :
**
** The append_to_buffer function append the characater c to the buffer passed
** passed in parameter.
**
** Param :buffer: the buffer to append the char c
** Param :c: the char to append
** Returns :void: nothing
**
** ---------------------------------------------------------------------------
*/

void	append_to_buffer(t_buffer *buffer, char c)
{
	if (buffer->cursor + 1 < BUFFER_SIZE)
	{
		buffer->buffer[buffer->cursor++] = c;
		buffer->accumulator++;
	}
	else
	{
		flush_buffer(buffer);
		buffer->cursor = 0;
		buffer->buffer[buffer->cursor++] = c;
		buffer->accumulator++;
	}
}
