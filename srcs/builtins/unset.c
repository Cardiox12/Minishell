/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:29:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/20 11:23:18 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "internals.h"
#include "builtins.h"

static int find_variable(const char *name)
{
    size_t index;
    size_t size;

    index = 0;
    while (g_env[index] != NULL)
    {
        size = ft_strlen(name);
        if (ft_strncmp(name, g_env[index], size) == 0)
            return (index);
        index++;
    }
    return (NOT_FOUND);
}

int unset(char **args)
{
    t_string_list   *copy;
    size_t          index;
    int             found;

    copy = NULL;
    string_list_create_from(&copy, g_env, ft_tablen(g_env));
    if (copy == NULL)
        return (0);
    index = 0;
    while (args[index] != NULL)
    {
        found = find_variable(args[index]);
        if (found != NOT_FOUND)
            string_list_pop(copy, found);
        index++;
    }
    string_list_append(copy, "");
    copy->items[copy->length - 1] = NULL;
    g_env = copy->items;
    return (0);
}