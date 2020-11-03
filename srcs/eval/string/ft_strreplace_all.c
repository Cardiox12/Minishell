/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:35:51 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 11:35:53 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static int		ft_get_next_str_ends(const char *haystack,
	const char *needle, int ends[2], int start)
{
	int i;
	int j;

	i = start;
	if (ft_strlen(needle) < 1)
		return (-1);
	if (needle == NULL)
		return (-1);
	j = 0;
	while (haystack[i])
	{
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!(needle[j]))
		{
			ends[0] = i;
			ends[1] = i + j;
			return (0);
		}
		else
			j = 0;
		i++;
	}
	return (-1);
}

char			*replace_one(char *string, char *replacement, int ends[2])
{
	char	*new_string;

	if (!(new_string = ft_strnew(ends[0] + ft_strlen(replacement)
		+ (ft_strlen(string) - ends[1]))))
		return (NULL);
	ft_strncpy(new_string, string, ends[0]);
	ft_allocat(&new_string, replacement);
	ft_allocat(&new_string, &(string[ends[1]]));
	return (new_string);
}

char			*ft_str_replace_all(char *string, char *to_find,
					char *replacement)
{
	int		ends[2];
	int		replacement_len;
	char	*new_string;
	char	*temp;

	if (string == NULL || to_find == NULL)
		return (NULL);
	if (ft_get_next_str_ends(string, to_find, ends, 0) == -1)
		return (ft_strdup(string));
	else
	{
		if (!(new_string = replace_one(string, replacement, ends)))
			return (NULL);
	}
	replacement_len = ft_strlen(replacement);
	while (ft_get_next_str_ends(new_string, to_find, ends, ends[0]
		+ replacement_len) != -1)
	{
		temp = new_string;
		if (!(new_string = replace_one(new_string, replacement, ends)))
			return (NULL);
		ft_strdel(&temp);
	}
	return (new_string);
}
