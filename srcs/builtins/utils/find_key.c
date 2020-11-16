/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:19:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:24:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	find_key(t_string_list *list, const char *key)
{
	const size_t	key_size = ft_strlen(key);
	size_t			index;

	index = 0;
	while (index < list->length)
	{
		if (ft_strncmp(list->items[index], key, key_size) == 0)
			return (index);
		index++;
	}
	return (NOT_FOUND);
}
