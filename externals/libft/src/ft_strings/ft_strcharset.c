/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 04:43:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/03 04:59:39 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

/*
**
**								ft_strcharset
**
** Description :
**
** The ft_strcharset function search for a character of charset into s and
** returns a pointer to the first occurrence.
**
** Param :s: the string to search into
** Param :charset: the charset to search into s
** Returns :char*: NULL if no occurrence found, otherwise a pointer to the
** first occurrence.
**
*/

char    *ft_strcharset(const char *s, const char *charset)
{
    size_t index;

    while (*s != '\0')
    {
        index = 0;
        while (charset[index] != '\0')
        {
            if (charset[index] == *s)
                return ((char*)s);
            index++;
        }
        s++;
    }
    return (NULL);
}