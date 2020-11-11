/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:29:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/11 01:53:35 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"
#include "internals.h"
#include "builtins.h"

static int find_variable_by_name(const char *name, t_string_list *sl_env)
{
    size_t index;
    size_t size;

    index = 0;
    while (sl_env->items[index] != NULL)
    {
        size = ft_strlen(name);
        if (ft_strncmp(name, sl_env->items[index], size) == 0)
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
        return (ERR_MALLOC_FAILED);
    index = 1;
    while (args[index] != NULL)
    {
        found = find_variable_by_name(args[index], copy);
        if (found != NOT_FOUND)
        {
            if (string_list_pop(copy, found) == ERR_MEM_ALLOC_FAILED)
                return (ERR_MALLOC_FAILED);
        }
        index++;
    }
    if (string_list_append(copy, "") == ERR_MEM_ALLOC_FAILED)
        return (ERR_MALLOC_FAILED);
    copy->items[copy->length - 1] = NULL;
    g_env = copy->items;
    return (SUCCESS);
}