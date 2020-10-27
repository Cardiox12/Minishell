/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:16:20 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/27 08:46:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char    *ft_strcpy(char *dst, const char *src)
{
    int index;

    index = 0;
    while (src[index] != '\0')
    {
        dst[index] = src[index];
        index++;
    }
    dst[index] = '\0';
    return (dst);
}