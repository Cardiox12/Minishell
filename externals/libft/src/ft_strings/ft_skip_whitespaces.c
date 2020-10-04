/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 05:07:59 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/03 05:23:44 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "ft_strings.h"

char    *skip_whitespaces(const char *s)
{
    while (*s != '\0' && ft_isspace(*s))
        s++;
    return ((char*)s);
}