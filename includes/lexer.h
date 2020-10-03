/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:18:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/03 05:57:03 by bbellavi         ###   ########.fr       */
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

typedef struct	s_interpret
{
	char		*input;
	t_queue		tokens;
}				t_interpret;

/*
**
** The following macros define token types
**
*/

# define COMMAND 1
# define STRING 2
# define ARGUMENT 3
# define PIPE 4
# define OPERATOR 5
# define ENV_VARIABLE 6
# define REDIRECTION 7
# define RAW_STRING 8

/*
**
** The following macros define lexer states
**
*/

enum	e_states
{
	IN_STRING = 0x01,
	IS_COMMAND = 0x01 << 1U
};

# define SYM_QUOTE '"'
# define SYM_SIMPLE_QUOTE '\''
# define SYM_PIPE '|'

t_queue	*queue_init(t_token token);
t_queue *enqueue(t_queue **head, t_token token);
t_queue	*dequeue(t_queue **head);
t_queue *lexer(const char *input);

#endif
