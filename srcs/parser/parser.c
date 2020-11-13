/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:16:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/13 14:44:02 by bbellavi         ###   ########.fr       */
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
            queue_free(inter->current);
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

    out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
    if (out != 0)
        return (out);
    while (is_type(inter->current->token.type, g_non_terminal_tokens, ARR_NON_TERM_SIZE))
    {
        out = eat(inter, g_non_terminal_tokens, ARR_NON_TERM_SIZE);
        if (out != 0)
            return (out);
    }
    return (SUCCESS);
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

int parse_error(t_interpret *inter, int out)
{
    int errtok;
    int index;

    if (out < 0)
    {
        queue_delete(&inter->tokens);
        return (SUCCESS);
    }
    index = inter->current->token.index;
    errtok = inter->input[index];
    ft_putstr_fd(EXE_NAME, STDERR_FILENO);
    ft_putchar_fd(':', STDERR_FILENO);
    ft_putchar_fd(' ', STDERR_FILENO);
    ft_putstr_fd(ERROR_SYNTAX, STDERR_FILENO);
    ft_putchar_fd(' ', STDERR_FILENO);
    ft_putchar_fd('`', STDERR_FILENO);
    ft_putchar_fd(errtok, STDERR_FILENO);
    if (errtok == inter->input[index + 1])
        ft_putchar_fd(errtok, STDERR_FILENO);
    ft_putchar_fd('\'', STDERR_FILENO);
    ft_putchar_fd('\n', STDERR_FILENO);
    queue_free(inter->current);
    queue_delete(&inter->tokens);
    return (out);
}

int parser(const char *input, t_queue *head)
{
    t_interpret inter;
    int         out;

    inter = (t_interpret){.input = (char*)input, .tokens = queue_copy(head)};
    inter.current = dequeue(&inter.tokens);
    out = commands(&inter);
    if (out != 0)
        return (parse_error(&inter, out));
    while (TRUE)
    {
        out = terminals(&inter);
        if (out != 0)
            return (parse_error(&inter, out));
        out = commands(&inter);
        if (out != 0)
            return (parse_error(&inter, out));
    }
    queue_free(inter.current);
    return (SUCCESS);
}