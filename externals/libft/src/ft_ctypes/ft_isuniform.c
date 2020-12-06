/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuniform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:18:06 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/07 00:41:16 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "ft_ctypes.h"

int	ft_isuniform(const char *s, int c)
{
	size_t index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != (unsigned char)c)
			return (FALSE);
		index++;
	}
	return (TRUE);
}
