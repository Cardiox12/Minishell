/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_enqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 06:14:39 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 17:17:31 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_queue	*enqueue(t_queue **head, t_token token)
{
	t_queue *current;
	t_queue *new;

	current = *head;
	new = queue_init(token);
	if (new == NULL)
		return (NULL);
	if (current == NULL)
		*head = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (new);
}
