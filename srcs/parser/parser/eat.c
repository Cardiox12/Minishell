/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:05:27 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:05:49 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	eat(t_interpret *inter, const int *types, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		if (inter->current == NULL)
			return (_EOF_);
		if (inter->current->token.type == types[index])
		{
			queue_free(inter->current);
			inter->current = dequeue(&inter->tokens);
			if (inter->current == NULL)
				return (_EOF_);
			return (SUCCESS);
		}
		index++;
	}
	return (ERR_PARSE);
}
