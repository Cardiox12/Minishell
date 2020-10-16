/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:31:18 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/16 13:55:33 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int     env(__unused char **args, char **envp)
{
    size_t index;

    index = 0;
    while (envp[index] != NULL)
        ft_printf("%s\n", envp[index++]);
    return (0); 
}