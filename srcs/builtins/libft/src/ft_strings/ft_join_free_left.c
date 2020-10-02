/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:47:04 by tlucille          #+#    #+#             */
/*   Updated: 2020/09/29 16:29:44 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

static void		ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char			*ft_join_free_left(char **s1, char *s2)
{
	char	*join;

	join = NULL;
	if (!(join = ft_strjoin(*s1, s2)))
		return (NULL);
	ft_strdel(s1);
	return (join);
}
