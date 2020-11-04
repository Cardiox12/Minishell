/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:35:13 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:35:14 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

char	*ft_alloncat(char **s1, const char *s2, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*s1)[i] != '\0')
		i++;
	while (s2[j] && (j < len))
	{
		(*s1)[i] = s2[j];
		i++;
		j++;
	}
	(*s1)[i] = '\0';
	return (*s1);
}