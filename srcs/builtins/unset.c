/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:29:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/21 15:39:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"
#include "builtins.h"

static int find_variable(const char *name, t_string_list *sl_env)
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

int putstr(const char *s)
{
    return (ft_printf("%s\n", s));
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
    index = 1;
    while (args[index] != NULL)
    {
        found = find_variable(args[index], copy);
        if (found != NOT_FOUND)
        {
            string_list_iter(copy, putstr);
            string_list_pop(copy, found);
        }
        index++;
    }
    string_list_append(copy, "");
    copy->items[copy->length - 1] = NULL;
    g_env = copy->items;
    return (0);
}