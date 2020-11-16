/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_spair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:29:29 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:17:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	free_spair(t_spair pair)
{
	if (pair.key != NULL)
		free(pair.key);
	if (pair.value != NULL)
		free(pair.value);
}
