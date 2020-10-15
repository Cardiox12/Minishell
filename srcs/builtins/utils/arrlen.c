/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:18:25 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/15 12:20:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/* We assume the string array is NULL-terminated */
size_t  arrlen(char **arr)
{
    size_t size;

    size = 0;
    while (arr[size] != NULL)
        size++;
    return (size);
}