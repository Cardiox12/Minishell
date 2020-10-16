/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:54:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/17 00:37:54 by bbellavi         ###   ########.fr       */
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

    // Get key / value from argument
    item = get_item(args[1]);

    // Init a dynamic list with based on envp
    string_list_create_from(&list, g_env, string_arr_len(g_env));

    index = find_key(list, item.key);
    if (index != NOT_FOUND)
    {
        // If env variable already exists
        // Replace the value by new value
        list->items[index] = args[1];
    }
    else
    {
        // If it does not already exists
        // Then add it to the end
        string_list_append(list, args[1]);
    }
    return (SUCCESS);
}