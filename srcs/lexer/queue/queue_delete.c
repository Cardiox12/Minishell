/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 02:24:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 17:17:01 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	queue_delete(t_queue **head)
{
	t_queue *current;
	t_queue *previous;

	current = *head;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
		queue_free(previous);
	}
	*head = NULL;
}
