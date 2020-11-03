/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:54:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/03 21:13:23 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internals.h"

static int find_key(t_string_list *list, const char *key)
{
    const size_t key_size = ft_strlen(key);
    size_t index;

    index = 0;
    while (index < list->length)
    {
        if (ft_strncmp(list->items[index], key, key_size) == 0)
            return (index);
        index++;
    }
    return (NOT_FOUND);
}

static t_spair get_item(const char *item)
{
    char    *sep;
    int     index;

    // We consider the item separate key / value by an equal sign.
    sep = ft_strchr(item, '=');
    if (sep == NULL)
        return ((t_spair){NULL, NULL});

    index = sep - item;
    return ((t_spair){
        .key = ft_strndup(item, index),
        .value = ft_strdup(&item[index])
    });
}

int export(char **args)
{
    t_spair         item;
    t_string_list   *list;
    int             index;

    if (args[1] == NULL)
        return (0);

    item = get_item(args[1]);

    string_list_create_from(&list, g_env, string_arr_len(g_env));

    index = find_key(list, item.key);
    if (index != NOT_FOUND)
    {
        list->items[index] = args[1];
    }
    else
    {
        string_list_append(list, args[1]);

    }
    g_env = list->items;
    free(list);
    free(item.key);
    free(item.value);
    return (SUCCESS);
}