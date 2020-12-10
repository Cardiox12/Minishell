/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:23:52 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 10:23:55 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "ft_strings.h"

int	ft_isnumeric(const char *s)
{
	size_t index;

	index = 0;
	if (s[index] == '\0')
		return (FALSE);
	while (s[index] != '\0')
	{
		if (!ft_isdigit(s[index]))
			return (FALSE);
		index++;
	}
	return (TRUE);
}
