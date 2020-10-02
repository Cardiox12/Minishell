/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:16:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 12:13:23 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

void	utoa(t_buffer *buffer, unsigned int number)
{
	if (number >= 10)
		utoa(buffer, number / 10);
	append_to_buffer(buffer, number % 10 + '0');
}
