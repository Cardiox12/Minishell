/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 05:13:59 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/29 05:25:23 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*
**
** Description :
**    The queue_init function init a t_queue node with the token passed
**    in parameter.
**
*/

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
