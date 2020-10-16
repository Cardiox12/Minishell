/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:54:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/16 16:06:52 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internals.h"

static int find_key(t_string_list *list, const char *key)
{
    size_t index;

    index = 0;
    while (index < list->length)
    {
        if (ft_strcmp(list->items[index], key) == 0)
            return (index);
        index++;
    }
    return (NOT_FOUND);
}

static t_spair get_item(char *item)
{
    t_spair pair;
    char    *sep;
    int     index;

    // We consider the item separate key / value by an equal sign.
    sep = ft_strchr(sep, '=');
    if (sep == NULL)
        return ((t_spair){NULL, NULL});

    index = sep - item;
    return ((t_spair){
        .key = ft_strndup(item, index),
        .value = ft_strdup(&item[index])
    });
}

int export(char **args, char **envp)
{
    t_spair         item;
    t_string_list   *list;

    if (args[1] == NULL)
        return (0);

    // Get key / value from argument
    item = get_item(args[1]);

    // Init a dynamic list with based on envp
    string_list_create_from(&list, envp, string_arr_len(envp));

    // If env variable already exists
    
    // If it does not already exists
    

    return (0);
}