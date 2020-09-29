/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:56:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:41:39 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

/*
** ---------------------------------------------------------------------------
**									Is full
**
** Description :
**
** The buffer_is_full function returns 1 if the buffer is full otherwise 0.
**
** Param :buffer: the buffer
** Returns :int: boolean
**
** ---------------------------------------------------------------------------
*/

int		buffer_is_full(t_buffer *buffer)
{
	if (buffer->cursor == BUFFER_SIZE - 1)
		return (1);
	return (0);
}
