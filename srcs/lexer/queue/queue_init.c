/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 05:13:59 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/03 10:51:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_queue	*queue_init(t_token token)
{
	t_queue *new;

	new = malloc(sizeof(t_queue));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->token = token;
	return (new);
}
