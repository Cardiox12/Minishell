/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_maker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:37:18 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:37:19 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int			*ft_int_tab_maker(size_t len)
{
	int				*int_tab;
	unsigned int	i;

	i = 0;
	if (!(int_tab = (int*)malloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		int_tab[i] = -1;
		i++;
	}
	int_tab[i] = -1;
	return (int_tab);
}
