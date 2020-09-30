/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 23:22:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 12:12:52 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "router.h"

void	ptoa(t_buffer *buffer, long long addr)
{
	if (addr >= HEX_BASE)
	{
		ptoa(buffer, addr / HEX_BASE);
		append_to_buffer(buffer, HEX_LOWER_BASE[addr % HEX_BASE]);
	}
	else
	{
		append_string_to_buffer(buffer, POINTER_PREFIX);
		append_to_buffer(buffer, HEX_LOWER_BASE[addr % HEX_BASE]);
	}
}
