/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:44:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/10 17:48:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void    free_env()
{
    int index;

    if (g_env != NULL)
    {
        index = 0;
        while (g_env[index] != NULL)
        {
            free(g_env[index]);
            index++;
        }
        free(g_env);
        g_env = NULL;
    }
}