/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_nbytes_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 02:49:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:33:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

void	append_nchar_to_buffer(t_buffer *buffer, const char *s, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
		append_to_buffer(buffer, s[index++]);
}
