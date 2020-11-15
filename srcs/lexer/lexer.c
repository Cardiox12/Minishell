/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:43:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 21:22:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "lexer.h"
#include "ft_stdio.h"

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
		if (!is_sep(input[index]) && ft_isprint(input[index]) && state & IS_COMMAND && !is_redirect(input[index]))
		{
			index = get_command(&head, input, index);
			state ^= IS_COMMAND;
			state |= IS_ARGUMENT;
		}
		else if (input[index] == '"' || input[index] == '\'')
		{
			index = get_string(&head, input, index);
		}
		else if (input[index] == '-' || (input[index] == '-' && input[index + 1] == '-'))
		{
			index = get_option(&head, input, index);
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
			state ^= IS_ARGUMENT;
		}
		else if (input[index] == SYM_ENV_VAR)
		{
			index = get_env_variable(&head, input, index);
		}
		else if (is_redirect(input[index]))
		{
			index = get_redirection(&head, input, index);
			state ^= IS_ARGUMENT;
			state |= IS_FD;
		}
        else if (is_bash_charset(input[index]) && state & IS_ARGUMENT)
        {
            index = get_argument(&head, input, index);
        }
		else if (state & IS_FD && !ft_isspace(input[index]))
		{
			index = get_fd(&head, input, index);
			state ^= IS_FD;
		}
		else
		{
			index++;
		}
	}
	return (head);
}