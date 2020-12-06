/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:41:34 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/06 20:22:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_queue	*queue_last(t_queue *queue)
{
	if (queue == NULL)
		return (NULL);
	while (queue->next != NULL)
		queue = queue->next;
	return (queue);
}
