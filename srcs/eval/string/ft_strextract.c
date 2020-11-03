/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:43:54 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:43:55 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_strings.h"

char		*ft_strextract(char const *s, char c, unsigned int index)
{
	char			*mlc;
	unsigned int	i;
	unsigned int	start;

	i = 0;
	if (s == NULL)
		return (NULL);
	start = index;
	while (s[index] != c)
		index++;
	if (!(mlc = (char*)malloc(sizeof(index - start + 1))))
		return (NULL);
	while (s[start] != c)
	{
		mlc[i] = s[start];
		i++;
		start++;
	}
	mlc[i] = '\0';
	return (mlc);
}
