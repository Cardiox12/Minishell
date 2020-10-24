/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:40:20 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/21 16:02:22 by bbellavi         ###   ########.fr       */
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
            return (g_builtins[index].callback(args));
        index++;
    }
    return (ERR_BUILTIN_NOT_FOUND);
}