/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:16:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/08 16:11:02 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int g_parse_err = 0;

static int check_begin(t_queue *origin)
{
    t_queue *copy;
    t_queue *curr;

    copy = queue_copy(origin);
    curr = dequeue(&copy);
    if (curr->token.type == PIPE && curr->token.index == 0)
        return (g_parse_err = ERR_PARSE);
    return (0);
}

int parser(t_queue *head)
{
    check_begin(head);
    if (g_parse_err != 0)
        return (g_parse_err);    
    return (0);
}