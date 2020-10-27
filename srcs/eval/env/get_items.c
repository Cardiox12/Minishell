/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 06:57:07 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/27 07:20:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_spair get_items(const char *e_var)
{
    char    *equal;
    int     index;
    t_spair items;

    equal = ft_strchr(e_var, SYM_EQUAL);
    if (equal == NULL)
        return ((t_spair){NULL, NULL});
    index = equal - e_var;
    if (index < 0)
        return ((t_spair){NULL, NULL});
    items.key = ft_strndup(e_var, index);
    if (items.key == NULL)
        return ((t_spair){NULL, NULL});
    items.value = ft_strndup(&e_var[index + 1], ft_strlen(e_var) - index);
    if (items.value == NULL)
    {
        free(items.key);
        return ((t_spair){NULL, NULL});
    }
    return (items);
}
