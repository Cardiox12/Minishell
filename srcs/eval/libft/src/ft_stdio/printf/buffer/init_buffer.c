/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:16:10 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:38:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

/*
** ---------------------------------------------------------------------------
**
**								Init buffer
**
** Description :
**
** The init_buffer function init the buffer with the following default values :
**
** buffer[BUFFER_SIZE]	= {0}
** cursor				= 0
** accumulator			= 0
**
** Param :void: nothing
** Returns :t_buffer*: the buffer that has been initialized
**
** ---------------------------------------------------------------------------
*/

void	init_buffer(t_buffer *buffer)
{
	size_t	index;

	index = 0;
	while (index < BUFFER_SIZE)
		buffer->buffer[index++] = 0;
	buffer->cursor = 0;
	buffer->accumulator = 0;
}
