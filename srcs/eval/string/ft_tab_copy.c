/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:48:01 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:48:04 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

char	**ft_tab_copy(char ***dst, char **src)
{
	int		i;
	int		len;

	i = 0;
	len = ft_tablen(src);
	if (!(*dst = ft_stabmaker(len)))
		return (NULL);
	while (src[i])
	{
		if (!((*dst)[i] = ft_strdup(src[i])))
			return (NULL);
		i++;
	}
	(*dst)[i] = 0;
	return (*dst);
}
