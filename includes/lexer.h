/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:18:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/09 02:27:58 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "ft_math.h"
# include "ft_strings.h"

typedef struct	s_token
{
	int			type;
	char		*value;
	size_t		index;
}				t_token;

typedef struct	s_queue
{
	struct s_queue	*next;
	t_token			token;
}				t_queue;

/*
**
** The following macros define token types
**
*/

# define COMMAND 1
# define STRING 2
# define OPTION 3
# define PIPE 4
# define OPERATOR 5
# define ENV_VARIABLE 6
# define REDIRECTION 7
# define RAW_STRING 8
# define FILE_DESCRIPTOR 9
# define ARGUMENT 10

# define ARR_ALL_TOK_SIZE 10
# define ARR_NON_TERM_SIZE 8
# define ARR_TERM_SIZE 2

static const int g_all_tokens[ARR_ALL_TOK_SIZE] = {
	COMMAND,
	STRING,
	OPTION,
	PIPE,
	OPERATOR,
	ENV_VARIABLE,
	REDIRECTION,
	RAW_STRING,
	FILE_DESCRIPTOR,
	ARGUMENT	
};

static const int g_non_terminal_tokens[ARR_NON_TERM_SIZE] = {
	COMMAND,
	STRING,
	RAW_STRING,
	OPTION,
	ARGUMENT,
	ENV_VARIABLE,
	REDIRECTION,
	FILE_DESCRIPTOR
};

static const int g_terminal_tokens[ARR_TERM_SIZE] = {OPERATOR, PIPE};

/*
**
** The following macros define lexer states
**
*/

enum	e_states
{
	IN_STRING = 0x01,
	IS_COMMAND = 0x01 << 1U,
	IS_FD = 0x01 << 2U,
	IS_ARGUMENT = 0x01 << 3U
};

# define SYM_QUOTE '"'
# define SYM_SIMPLE_QUOTE '\''
# define SYM_PIPE '|'
# define SYM_OPERATOR ';'
# define SYM_ENV_VAR '$'
# define SYM_R_REDIR '>'
# define SYM_L_REDIR '<'
# define SYM_EQUAL '='

t_queue	*queue_init(t_token token);
t_queue *queue_copy(t_queue *origin);
t_queue *enqueue(t_queue **head, t_token token);
t_queue	*dequeue(t_queue **head);
void    queue_free(t_queue *node);
void    queue_delete(t_queue **head);
t_queue *lexer(const char *input);

#endif
