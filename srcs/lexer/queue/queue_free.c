/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:56:12 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 16:40:28 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	queue_free(t_queue *node)
{
	if (node != NULL)
	{
		if (node->token.value != NULL)
			free(node->token.value);
		free(node);
	}
}
