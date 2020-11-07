/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:40:20 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/06 20:48:01 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int builtins_call(char **args)
{
    size_t size;
    size_t index;

    index = 0;
    if (*args == NULL)
        return (ERR_BUILTIN_NOT_FOUND);
    size = ft_strlen(*args);
    while (index < BUILTINS_SIZE)
    {
        if (ft_strncmp(g_builtins[index].func_name, *args, size) == 0)
        {
            g_exitstatus = g_builtins[index].callback(args);
            return (g_exitstatus);
        }
        index++;
    }
    return (ERR_BUILTIN_NOT_FOUND);
}