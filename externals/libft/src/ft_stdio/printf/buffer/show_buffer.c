/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:30:03 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:38:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

/*
** ---------------------------------------------------------------------------
**
**								Show buffer
**
** Description : The show_buffer function show the buffer
** Param :buffer: the buffer to print
** Returns :void: nothing
**
** ---------------------------------------------------------------------------
*/

void	show_buffer(t_buffer *buffer)
{
	write(1, buffer->buffer, buffer->cursor);
}
