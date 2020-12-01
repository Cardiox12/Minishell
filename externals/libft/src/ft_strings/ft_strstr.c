/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:55:21 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/01 21:57:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	return (ft_strnstr(haystack, needle, ft_strlen(haystack)));
}
