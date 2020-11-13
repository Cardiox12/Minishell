/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_charset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 03:33:12 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/11 03:44:43 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char    *ft_skip_charset(char *s, const char *charset)
{
    int index;

    index = 0;
    while (*s != '\0')
    {
        if (ft_strchr(charset, *s) == NULL)
            return (s);
        s++;
    }
    return (s);
}