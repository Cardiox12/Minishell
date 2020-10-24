/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringList_create_from.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:27:45 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/20 11:07:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_objects.h"

void    string_list_create_from(t_string_list **lst, char **arr, size_t size)
{
    t_string_list *new;

    new = NULL;
    string_list_create(&new);
    if (new == NULL)
        *lst = NULL;
    else
    {
        new->items = arr;
        new->length = size;
        *lst = new;   
    }
}