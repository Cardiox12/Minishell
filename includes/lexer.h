/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:18:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/01 12:05:23 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "ft_strings.h"

typedef struct	s_token
{
	int			type;
	char		*value;
	int			index;
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
	ISNT_FIRST = 0x01 << 1U
};

t_queue	*queue_init(t_token token);
t_queue *enqueue(t_queue **head, t_token token);
t_queue	*dequeue(t_queue **head);

#endif
