/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:18:31 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/25 18:21:39 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

char	*get_value(const char *e_var)
{
	t_spair items;

	if (e_var == NULL)
		return (ft_strdup(""));
	items = get_items(e_var);
	if (items.first == NULL && items.second == NULL)
		return (NULL);
	free(items.first);
	return (items.second);
}
