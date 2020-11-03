/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:43:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/03 04:49:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "lexer.h"
#include "ft_stdio.h"

static int is_redirect(int c)
{
	return (c == SYM_L_REDIR || c == SYM_R_REDIR);
}

static int is_sep(int c)
{
	return (ft_isspace(c) || c == SYM_PIPE || c == SYM_OPERATOR);
}

static char *quote_extract(const char *input, size_t *index)
{
	const int	quote = input[*index];
	size_t		previous;
	char		*content;

	while (input[*index] == quote)
		(*index)++;
	previous = *index;
	while (input[*index] != quote)
		(*index)++;
	content = ft_strndup(&input[previous], *index - previous);
	while (input[*index] == quote)
		(*index)++;
	return (content);	

}

static int get_command(t_queue **head, const char *input, size_t index)
{
    const size_t	previous = index;
	char			*content;

	if (ft_isquote(input[index]))
	{
		content = quote_extract(input, &index);
	}
	else
	{
		while (input[index] != '\0' && !is_sep(input[index]))
			index++;
		content = ft_strndup(&input[previous], index - previous);
	}
    enqueue(head, (t_token){
        .type = COMMAND,
        .value = content,
        .index = previous
    });
    return (index);
}

static int get_env_variable(t_queue **head, const char *input, size_t index)
{
    const size_t previous = index;
    
    while (input[index] != '\0' && !is_sep(input[index]))
        index++;
    enqueue(head, (t_token){
        .type = ENV_VARIABLE,
        .value = ft_strndup(&input[previous], index - previous),
        .index = previous
    });
    return (index);
}

static int get_string(t_queue **head, const char *input, size_t index)
{	
	size_t	previous;
    int		type;
	char	*content;

	previous = index;
    if (input[index] == SYM_SIMPLE_QUOTE)
	{
        type = RAW_STRING;
	}
    else
	{
        type = STRING;
	}
	content = quote_extract(input, &index);
    enqueue(head, (t_token){
        .type = type,
        .value = content,
        .index = previous
    });
    return (index);
}

static int get_option(t_queue **head, const char *input, size_t index)
{
    const size_t previous = index;

    while (input[index] != '\0' && !is_sep(input[index]))
        index++;
    enqueue(head, (t_token){
        .type = OPTION,
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

static int get_redirection(t_queue **head, const char *input, size_t index)
{
	const size_t previous = index;

	if (input[index] == SYM_R_REDIR && input[index + 1] == SYM_R_REDIR)
		index += 2;
	else if (input[index] == SYM_R_REDIR || input[index] == SYM_L_REDIR)
		index++;
	enqueue(head, (t_token){
		.type = REDIRECTION,
		.value = ft_strndup(&input[previous], index - previous),
		.index = index
	});
	return (index);
}

static int get_fd(t_queue **head, const char *input, size_t index)
{
	const size_t previous = index;

	while (!is_sep(input[index]) && input[index] != '\0')
		index++;
	enqueue(head, (t_token){
		.type = FILE_DESCRIPTOR,
		.value = ft_strndup(&input[previous], index - previous),
		.index = previous
	});
	return (index);
}

static int get_argument(t_queue **head, const char *input, size_t index)
{
    const size_t previous = index;

    while (!is_sep(input[index]) && input[index] != '\0')
        index++;
    enqueue(head, (t_token){
        .type = ARGUMENT,
        .value = ft_strndup(&input[previous], index - previous),
        .index = previous
    });
    return (index);
}

static int is_bash_charset(int c)
{
	return (ft_isprint(c) && !is_sep(c));
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