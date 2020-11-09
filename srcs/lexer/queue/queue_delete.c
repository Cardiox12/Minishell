/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 02:24:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/09 02:28:28 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void    queue_delete(t_queue **head)
{
    t_queue *current;

    while ((current = dequeue(head)) != NULL)
    {
        queue_free(current);
    }
    *head = NULL;
}