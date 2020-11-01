/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 01:10:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/01 20:11:55 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "eval.h"

static int  is_var_charset(int c)
{
    return (ft_isalnum(c) || c == '_');
}

static char *extract_and_replace(char *src, const char *value, t_slice slice)
{
    const size_t    slength = ft_strlen(src);
    const size_t    vlength = ft_strlen(value);
    size_t          total;
    char            *new;
    
    total = slice.begin + vlength + (slength - slice.end);
    
    new = malloc(sizeof(char) * (total + 1));
    
    if (new == NULL)
        return (NULL);

    ft_bzero(new, total);
    ft_strncpy(new, src, slice.begin);
    ft_strcpy(&new[slice.begin], value);
    ft_strcpy(&new[slice.begin + vlength], &src[slice.end]);
    return (new);
}

static char *replace(char **src, t_slice slice)
{
    char    *previous;
    t_spair items;

    items.key = ft_substr(*src, slice.begin + 1, slice.end - (slice.begin + 1));
    if (items.key == NULL)
        return (NULL);
    items.value = get_value(find_variable(items.key));
    if (items.value == NULL)
        items.value = ft_strdup("");
    previous = *src;
    *src = extract_and_replace(*src, items.value, slice);
    free(previous);
    return (*src);
}

char    *expand(const char *src)
{
    char    *new;
    t_slice slice;

    slice.begin = 0;
    if ((new = ft_strdup(src)) == NULL)
        return (NULL);
    while (new[slice.begin] != '\0')
    {
        if (new[slice.begin] == SYM_ENV_VAR && is_var_charset(new[slice.begin + 1]))
        {
            slice.end = slice.begin + 1;
            while (is_var_charset(new[slice.end]) && new[slice.end] != '\0')
                slice.end++;       
            replace(&new, slice);
            slice.begin = 0;
        }
        else
            slice.begin++;
    }
    return (new);
}