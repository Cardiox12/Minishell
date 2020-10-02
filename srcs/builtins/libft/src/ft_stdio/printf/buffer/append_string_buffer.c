/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_string_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:45:17 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:36:14 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

/*
** ---------------------------------------------------------------------------
**
**							Append string buffer
**
** Description :
**
** The append_string_to_buffer function append the null terminated string s to
** the buffer passed in parameter.
**
** Param :buffer: the buffer to append the string s
** Param :s: the string to append
** Returns :void: nothing
**
** ---------------------------------------------------------------------------
*/

void	append_string_to_buffer(t_buffer *buffer, const char *s)
{
	while (*s)
		append_to_buffer(buffer, *s++);
}
