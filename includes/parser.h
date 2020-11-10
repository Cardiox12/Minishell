/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:11:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/10 01:34:46 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "lexer.h"
# include "internal_errors.h"

typedef struct	s_interpret
{
	char		*input;
	t_queue		*tokens;
	t_queue		*current;
}				t_interpret;

enum	e_parse_errors
{
	ERR_PARSE	= 1,
	EOF_		= 2
};

# define _EOF_ -1

int parser(const char *input, t_queue *head);

#endif