/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_spair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:29:29 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/25 18:22:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	free_spair(t_spair pair)
{
	if (pair.first != NULL)
		free(pair.first);
	if (pair.second != NULL)
		free(pair.second);
}
