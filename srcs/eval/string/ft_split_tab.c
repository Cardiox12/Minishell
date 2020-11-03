/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:40:24 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:40:25 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static unsigned int	word_counter(char const *str, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (i < ft_strlen(str))
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static char			**stab_maker(size_t len)
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

static char			*s_extractor(char const *s, char c, unsigned int index)
{
	char			*mlc;
	unsigned int	i;
	unsigned int	start;

	i = 0;
	while (s[index] == c)
		index++;
	start = index;
	while (s[index] && s[index] != c)
		index++;
	if (!(mlc = ft_strnew(index - start)))
		return (NULL);
	while (s[start] && s[start] != c)
	{
		mlc[i] = s[start];
		i++;
		start++;
	}
	mlc[i] = '\0';
	return (mlc);
}

static char			**free_tab(char **tab, int k)
{
	while (--k >= 0)
		ft_strdel(&tab[k]);
	free(tab);
	return (NULL);
}

char				**ft_split_tab(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	int				k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = stab_maker(word_counter(s, c))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (i < ft_strlen(s))
		{
			if (!(tab[k] = s_extractor(s, c, i)))
				return (free_tab(tab, k));
			i = i + ft_strlen(tab[k]);
			k++;
		}
	}
	tab[k] = 0;
	return (tab);
}
