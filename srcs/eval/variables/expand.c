/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 01:10:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/28 16:48:13 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "eval.h"

/*
** Expand variables into src.
*/

static char *glue(const char *src, const char *value, t_slice slice)
{
    size_t v_size;
    size_t end_size;
    size_t total_size;
    char *string;

    v_size = ft_strlen(value);
    end_size = ft_strlen(src) - slice.end;
    total_size = slice.begin + v_size + end_size;

    string = malloc(sizeof(char) * (total_size + 1));
    if (string == NULL)
        return (NULL);

    ft_strncpy(string, src, slice.begin);
    ft_strncpy(&string[slice.begin], value, v_size);
    ft_strcpy(&string[slice.begin + v_size], &src[slice.end]);
    string[total_size] = '\0';
    return (string);
}

char    *replace(const char *src, t_slice slice)
{
    char *key;
    char *ret;

    // Find the variable to expand
    if (slice.begin > slice.end)
        return (NULL);
    key = ft_strndup(&src[slice.begin + 1], slice.end - (slice.begin + 1));
    if (key == NULL)
        return (NULL);
    
    char *e_var = find_variable(key);
    t_spair items = get_items(e_var);

    if (items.key == NULL || items.value == NULL)
        return (NULL);

    ret = glue(src, items.value, slice);
    return (ret);
}

char    *expand(const char *src)
{
    t_vec   index;
    char    *expanded;

    index.x = 0;
    expanded = (char*)src;
    while (expanded[index.x] != '\0')
    {
        if (expanded[index.x] == SYM_ENV_VAR)
        {
            index.y = index.x;
            while (!ft_isspace(expanded[index.y]) && expanded[index.y] != '\0')
                index.y++;
            expanded = replace(expanded, (t_slice){index.x, index.y});            
            if (expanded == NULL)
                return (NULL);
            index.x = index.y;
        }
        index.x++;
    }
    return (expanded);
}