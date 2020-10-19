/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:29:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/19 21:50:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "internals.h"
#include "builtins.h"

static int find_name(const char *name)
{
    const size_t size = ft_strlen(name);
    int index;

    index = 0;
    while (g_env[index] != NULL)
    {
        if (ft_strncmp(name, g_env[index], size) == 0)
            return (index);
        index++;
    }
    return (NOT_FOUND);
}

static t_indices find_names(char **args)
{
    t_indices   indices;
    size_t      index;

    indices.length = ft_tablen(args);
    indices.indices = malloc(sizeof(int) * indices.length);
    if (indices.indices == NULL)
        return (indices);
    index = 0;
    while (args[index] != NULL)
    {
        indices.indices[index] = find_name(args[index]);
        index++;
    }
    return (indices);
}

static size_t get_new_size(t_indices indices)
{
    size_t size;

    size = 0;
    while (indices.length > 0)
    {
        if (*indices.indices == NOT_FOUND)
            size++;
        indices.indices++;
        indices.length--;   
    }
    return (size);
}

int unset(char **args)
{
    t_indices   indices;
    char        **new_env;
    size_t      new_size;
    t_vec       i;

    indices = find_names(args);
    
    if (indices.indices == NULL)
        return (0);
    
    new_size = get_new_size(indices);
    if (new_size == 0)
        return (0);
        
    new_env = malloc(sizeof(char*) * (new_size + 1));
    i.x = 0;
    i.y = 0;
    while (i.x < indices.length)
    {
        if (indices.indices[i.x] == NOT_FOUND)
        {
            new_env[i.y] = g_env[i.x];
            i.y++;
        }
        i.x++;
    }
    new_env[i.y] = NULL;
    free(g_env);
    g_env = new_env;
    return (0);
}