/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:46:15 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:46:21 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static int		ft_get_str_ends(const char *haystack,
					const char *needle, int ends[2])
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(needle) < 1)
		return (-1);
	if (needle == NULL)
		return (-1);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!(needle[j]))
		{
			ends[0] = i;
			ends[1] = i + j;
			return (0);
		}
		i++;
	}
	return (-1);
}

char			*ft_str_replace(char *string, char *to_find, char *replacement)
{
	int		ends[2];
	char	*new_string;

	if (string == NULL)
		return (NULL);
	if (to_find == NULL)
		return (NULL);
	if (ft_get_str_ends(string, to_find, ends) == -1)
		return (ft_strdup(string));
	if (!(new_string = ft_strnew(ends[0] + ft_strlen(replacement)
		+ (ft_strlen(string) - ends[1]))))
		return (NULL);
	ft_strncpy(new_string, string, ends[0]);
	ft_allocat(&new_string, replacement);
	ft_allocat(&new_string, &(string[ends[1]]));
	return (new_string);
}
