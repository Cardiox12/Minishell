/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:18:31 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:46:58 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

char	*get_value(const char *e_var)
{
	t_spair items;

	if (e_var == NULL)
		return (ft_strdup(""));
	items = get_items(e_var);
	if (items.key == NULL && items.value == NULL)
		return (NULL);
	free(items.key);
	return (items.value);
}
