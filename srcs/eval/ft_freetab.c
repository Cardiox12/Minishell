/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:56:24 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/02 19:56:26 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void	ft_freetab(char ***tab)
{
	int i;

	i = ft_tablen(*tab);
	while (--i >= 0)
		ft_strdel(&((*tab)[i]));
	free(*tab);
	tab = NULL;
}
