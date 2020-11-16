/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:06:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:06:57 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_type(int cur_type, const int *types, size_t size)
{
	size_t index;

	index = 0;
	while (index < size)
	{
		if (cur_type == types[index])
			return (TRUE);
		index++;
	}
	return (FALSE);
}
