/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:43:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/02 19:07:28 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "lexer.h"
#include "ft_stdio.h"

static t_token get_command(const char *input, size_t index)
{
    const size_t previous = index;

    while (!ft_isspace(input[index]) && input[index] != '\0')
        index++;
    ft_printf("index - previous = %i\n", index - previous);
    ft_printf("input : %s\n", input);
    ft_printf("value : %s\n", ft_strndup(input, index - previous));
    return ((t_token){COMMAND, ft_strndup(input, index - previous), previous});
}

static t_token get_string(const char *input, size_t index)
{
    const size_t previous = index;

    while (ft_isquote(input[index]) && input[index] != '\0')
        index++;
    return ((t_token){STRING, ft_strndup(input, index - previous), previous});
}

t_queue *lexer(const char *input)
{
    const size_t    length = ft_strlen(input);
    t_queue         *head;
    uint8_t         state;
    size_t          index;

    head = NULL;
    index = 0;
    state = IS_COMMAND;
    while (index < length)
    {
        if (ft_isalpha(input[index]) && state & IS_COMMAND)
        {
            enqueue(&head, get_command(input, index));
            while (!ft_isspace(input[index]) && index < length)
                index++;
            state ^= IS_COMMAND;
        }
        if (input[index] == '"' || input[index] == '\'')
        {
            enqueue(&head, get_string(input, index));
            while (!ft_isspace(input[index]) && index < length)
                index++;
        }
        index++;
    }
    return (head);
}