/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_alnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 05:09:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/03 05:23:13 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "ft_strings.h"

char    *skip_alnum(const char *s)
{
    while (*s != '\0' && ft_isalnum(*s))
        s++;
    return ((char*)s);
}