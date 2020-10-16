/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:31:18 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/16 13:50:35 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int     env(__unused char **args, char **env)
{
    size_t index;

    index = 0;
    while (env[index] != NULL)
        ft_printf("%s\n", env[index++]);
    return (0); 
}