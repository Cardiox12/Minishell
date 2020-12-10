/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:27:10 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 01:29:44 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>

t_queue	*queue_join(t_queue *head)
{
	t_queue *final;
	t_queue *cur;
	t_token token;

	if ((cur = head) == NULL)
		return (NULL);
	final = NULL;
	while (cur != NULL)
	{
		token = token_copy(cur->token);
		if (token.prefixed)
		{
			while (cur->next != NULL && cur->token.prefixed)
			{
				strjoin(&token.value, cur->next->token.value);
				cur = cur->next;
			}
		}
		enqueue(&final, token);
		cur = cur->next;
	}
	queue_delete(&head);
	return (final);
}
