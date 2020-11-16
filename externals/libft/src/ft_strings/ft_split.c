/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:39:01 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:46:51 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

t_string_list	*ft_split(char const *s, char c)
{
	t_string_list	*list;
	char			*found;
	char			*iter;

	list = NULL;
	string_list_create(&list);
	if (list == NULL)
		return (NULL);
	iter = (char*)s;
	while (*iter != '\0')
	{
		if ((found = ft_strchr(iter, c)) != NULL ||
		(found = ft_strchr(iter, '\0')))
		{
			string_list_append(list, ft_strndup(iter, found - iter));
			iter = found;
			while (*iter != '\0' && *iter == c)
				iter++;
		}
		else
			iter++;
	}
	return (list);
}
