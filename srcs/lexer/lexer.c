/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:43:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/03 08:18:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "lexer.h"
#include "ft_stdio.h"

static int get_command(t_queue **head, const char *input, size_t index)
{
    const size_t previous = index;

    while (input[index] != '\0' && !ft_isspace(input[index]))
        index++;
    enqueue(head, (t_token){
        .type = COMMAND,
        .value = ft_strndup(&input[previous], index - previous),
        .index = previous
    });
    return (index);
}

static int get_string(t_queue **head, const char *input, size_t index)
{
    const size_t    previous = index;
    const int       quote = input[index];
    int             type;

    if (quote == SYM_SIMPLE_QUOTE)
        type = RAW_STRING;
    else
        type = STRING;
    ++index;
    while (input[index] != '\0' && !ft_isspace(input[index]))
        index++;
    enqueue(head, (t_token){
        .type = type,
        .value = ft_strndup(&input[previous], index - previous),
        .index = previous
    });
    return (index);
}

static int get_argument(t_queue **head, const char *input, size_t index)
{
    const size_t previous = index;

    while (input[index] != '\0' && !ft_isspace(input[index]))
        index++;
    enqueue(head, (t_token){
        .type = ARGUMENT,
        .value = ft_strndup(&input[previous], index - previous),
        .index = previous
    });
    return (index);
}

static int get_pipe(t_queue **head, size_t index)
{
    enqueue(head, (t_token){
        .type = PIPE,
        .value = ft_strdup("|"),
        .index = index
    });
    return (++index);
}

static int get_operator(t_queue **head, size_t index)
{
    enqueue(head, (t_token){
        .type = OPERATOR,
        .value = ft_strdup(";"),
        .index = index
    });
    return (++index);
}

t_queue *lexer(const char *input)
{
    const size_t    length = ft_strlen(input);
    t_queue         *head;
    int             state;
    size_t          index;

    head = NULL;
    index = 0;
    state = IS_COMMAND;
    while (index < length)
    {
        if (ft_isalpha(input[index]) && state & IS_COMMAND)
        {
            index = get_command(&head, input, index);
            state ^= IS_COMMAND;
        }
        else if (input[index] == '"' || input[index] == '\'')
        {
            index = get_string(&head, input, index);
        }
        else if (input[index] == '-' || (input[index] == '-' && input[index + 1] == '-'))
        {
            index = get_argument(&head, input, index);
        }
        else if (input[index] == SYM_PIPE)
        {
            index = get_pipe(&head, index);
            state ^= IS_COMMAND;
        }
        else if (input[index] == SYM_OPERATOR)
        {
            index = get_operator(&head, index);
            state ^= IS_COMMAND;
        }
        else
        {
            index++;
        }
    }
    return (head);
}