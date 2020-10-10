/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:16:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/10 20:41:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"

int eat(t_interpret *inter, int *types, size_t size)
{
    size_t  index;
    t_queue *current;

    index = 0;
    while (index < size)
    {
        if (inter->current.type == types[index])
        {
            current = dequeue(&inter->tokens);
            if (current == NULL)
                return (_EOF_);
            inter->current = current->token;
            return (NO_ERROR);
        }
        index++;
    }
    return (ERR_PARSE);
}

int parser(const char *input, t_queue *head)
{
    t_interpret inter;
    t_queue     *current;

    // Initialization of interpreter
    inter = (t_interpret){.input = (char*)input, .tokens = queue_copy(head)};

    // Dequeue tokens queue to compare to the first item
    current = dequeue(&inter.tokens);

    // Affecting the token to the current token to compare
    inter.current = current->token;

    // Freeing the current queue item
    free(current);

    if (eat(&inter, (int*)g_all_tokens, 10) > 0)
        return (ERR_PARSE);
    if (eat(&inter, (int[3]){STRING, RAW_STRING, ARGUMENT}, 3) > 0)
        return (ERR_PARSE);
    return (0);
}