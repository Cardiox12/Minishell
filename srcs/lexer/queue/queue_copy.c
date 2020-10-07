/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 03:39:05 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/07 16:25:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_queue *queue_copy(t_queue *origin)
{
    t_queue *copy;

    copy = NULL;
    while (origin != NULL)
    {
        enqueue(&copy, origin->token);
        origin = origin->next;
    }
    return (copy);
}