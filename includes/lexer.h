/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:18:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/09 01:04:35 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

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

static int g_all_tokens[9] = {
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
t_queue *lexer(const char *input);

#endif
