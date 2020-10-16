/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:31:18 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/17 00:37:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int     env(__unused char **args)
{
    size_t index;

    index = 0;
    while (g_env[index] != NULL)
        ft_printf("%s\n", g_env[index++]);
    return (0);
}