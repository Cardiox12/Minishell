/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:10:04 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/03 21:21:04 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_queue	*queue_pop_last(t_queue *head)
{
	t_queue *last;

	if (head == NULL)
		return (NULL);
	if (head->next == NULL)
		return (head);
	while (head->next->next != NULL)
		head = head->next;
	last = head->next;
	head->next = NULL;
	return (last);
}