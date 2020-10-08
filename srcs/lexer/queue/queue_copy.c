/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 03:39:05 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/07 18:29:02 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_queue *queue_copy(t_queue *origin)
{
    t_queue *copy;
    t_token token;

    copy = NULL;
    while (origin != NULL)
    {
        token = origin->token;
        token.value = ft_strdup(origin->token.value);
        enqueue(&copy, token);
        origin = origin->next;
    }
    return (copy);
}