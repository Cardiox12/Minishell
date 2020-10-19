/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:29:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/19 16:37:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int unset(char **args)
{
    size_t index;

    index = 0;
    while (args[index] != NULL)
    {
        // Find the item
        // If item exists
        //      - Remove item
        index++;
    }
    return (0);
}