/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:11:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/10 20:38:46 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "lexer.h"
# include "error.h"

typedef struct	s_interpret
{
	char		*input;
	t_queue		*tokens;
	t_token		current;
}				t_interpret;

enum	e_parse_errors
{
	ERR_PARSE	= 1,
	EOF_		= 2
};

# define _EOF_ -1

int parser(const char *input, t_queue *head);

#endif