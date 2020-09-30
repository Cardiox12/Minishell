/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_dequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:09:45 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 09:20:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*
**
** Description :
**    The dequeue function remove first item of the queue.
**
*/

t_queue	*dequeue(t_queue **head)
{
	t_queue *first;

	first = *head;
	if (first == NULL)
		return (NULL);
	*head = (*head)->next;
	return (first);
}