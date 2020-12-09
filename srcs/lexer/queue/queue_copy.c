/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 03:39:05 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 01:01:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	token_copy(t_token token)
{
	return ((t_token){
		.index = token.index,
		.type = token.type,
		.value = ft_strdup(token.value),
		.prefixed = token.prefixed
	});
}

t_queue	*queue_copy(t_queue *origin)
{
	t_queue	*copy;

	copy = queue_init(token_copy(origin->token));
	if (copy == NULL)
		return (NULL);
	return (copy);
}

t_queue	*queue_copy_all(t_queue *origin)
{
	t_queue *copy;
	t_token token;

	copy = NULL;
	while (origin != NULL)
	{
		token = token_copy(origin->token);
		enqueue(&copy, token);
		origin = origin->next;
	}
	return (copy);
}
