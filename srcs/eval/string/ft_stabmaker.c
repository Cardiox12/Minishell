/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stabmaker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:42:18 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:42:19 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

char		**ft_stabmaker(size_t len)
{
	char			**stab;
	unsigned int	i;

	i = 0;
	if (!(stab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		stab[i] = 0;
		i++;
	}
	stab[i] = 0;
	return (stab);
}
