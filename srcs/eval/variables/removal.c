/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:23:54 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 03:24:20 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "lexer.h"

static t_vec	get_pair_size(t_spair pair)
{
	return ((t_vec){
		ft_strlen(pair.key),
		ft_strlen(pair.value)
	});
}

char			*removal(char **src, t_slice slice)
{
	t_vec	sizes;
	char	*old;
	char	*begin;
	char	*end;

	begin = ft_substr(*src, 0, slice.begin);
	end = ft_substr(*src, slice.begin + 1,
	ft_strlen(&((*src)[slice.begin + 1])));
	old = *src;
	if (begin == NULL)
		return (NULL);
	if (end == NULL)
	{
		free(begin);
		return (NULL);
	}
	sizes = get_pair_size((t_spair){begin, end});
	*src = ft_strnew(sizes.x + sizes.y);
	free(old);
	ft_strlcat(*src, begin, sizes.x + sizes.y + 1);
	ft_strlcat(*src, end, sizes.x + sizes.y + 1);
	free(begin);
	free(end);
	return (*src);
}
