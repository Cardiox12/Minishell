/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:16:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/12 14:41:38 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "lexer.h"
#include "parser.h"

int is_type(int cur_type, const int *types, size_t size)
{
    size_t index;

    index = 0;
    while (index < size)
    {
        if (cur_type == types[index])
            return (TRUE);
        index++;
    }
    return (FALSE);
}

int eat(t_interpret *inter, const int *types, size_t size)
{
    size_t  index;

    index = 0;
    while (index < size)
    {
        if (inter->current == NULL)
            return (_EOF_);
        if (inter->current->token.type == types[index])
        {
            inter->current = dequeue(&inter->tokens);
            if (inter->current == NULL)
                return (_EOF_);
            return (SUCCESS);
        }
        index++;
    }
    return (ERR_PARSE);
}

int commands(t_interpret *inter)
{
    int out;

    // We should verify that the bash grammar is composed of
    // the following grammar :
    // pipeline: command (STRING|ARG|OPT|)

    // Check if it begin by any token
    out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
    if (out != 0)
        return (out);
    
    // Check if there are 
    while (is_type(inter->current->token.type, g_non_terminal_tokens, ARR_NON_TERM_SIZE))
    {
        out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
        if (out != 0)
            return (out);
    }
    return (0);
}

int terminals(t_interpret *inter)
{
    int out;
    
    if (is_type(inter->current->token.type, g_terminal_tokens, ARR_TERM_SIZE))
    {
        out = eat(inter, g_terminal_tokens, ARR_TERM_SIZE);
        if (out != 0)
            return ((out < 0) ? SUCCESS : out);
    }
    return (SUCCESS);
}

int parser(const char *input, t_queue *head)
{
    t_interpret inter;
    int         out;

    // Initialization of interpreter
    inter = (t_interpret){.input = (char*)input, .tokens = queue_copy(head)};

    // Dequeue tokens queue to compare to the first item
    inter.current = dequeue(&inter.tokens);

    out = commands(&inter);
    if (out != 0)
        return ((out < 0) ? SUCCESS : out);

    while (1)
    {
        out = terminals(&inter);
        if (out != 0)
            return ((out < 0) ? SUCCESS : out);

        out = commands(&inter);
        if (out != 0)
            return ((out < 0) ? SUCCESS : out);
    }
    return (SUCCESS);
}