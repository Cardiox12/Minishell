/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 01:10:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/25 21:02:49 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "eval.h"

/*
** Expand variables into src.
*/

char    *replace(const char *src, t_slice slice)
{
    
}

char    *expand(const char *src)
{
    t_vec   index;
    char    *expanded;

    index.x = 0;
    while (src[index.x] != '\0')
    {
        if (src[index.x] == SYM_ENV_VAR)
        {
            index.y = index.x;
            while (!ft_isspace(src[index.y]) && src[index.y] != '\0')
                index.y++;
            expanded = replace(src, (t_slice){index.x, index.y});            
            index.x = index.y;
        }
        index.x++;
    }
    return (NULL);
}