/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_dequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:09:45 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/03 10:47:19 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_queue	*dequeue(t_queue **head)
{
	t_queue	*first;

	first = *head;
	if (first == NULL)
		return (NULL);
	*head = (*head)->next;
	return (first);
}
