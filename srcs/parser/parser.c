/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:16:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/09 01:22:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "includes/parser.h"

int eat(t_interpret *inter, int *types, int size)
{
    size_t index;

    index = 0;
    while (index < size)
    {
        if (inter->current.type == types[index])
        {
            inter->current = dequeue(&inter->tokens);
        }
    }
    return (0);
}

int parser(const char *input, t_queue *head)
{
    t_interpret inter;

    inter = (t_interpret){
        .input = input,
        .tokens = queue_copy(head)
    };
    // eat(&inter, (int[5]){STRING, ARGUMENT, }, 5);
    return (0);
}