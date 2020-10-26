/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:02:08 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/25 21:05:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

/* 
**
** Find variable into env array and returns key/value string.
**
*/

char    *find_variable(const char *key)
{
    const size_t k_size = ft_strlen(key);
    size_t index;

    index = 0;
    while (g_env[index] != NULL)
    {
        if (ft_strncmp(g_env[index], key, k_size) == 0)
            return (g_env[index]);
        index++;
    }
    return (NULL);
}