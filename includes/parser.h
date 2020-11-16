/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:11:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:13:54 by bbellavi         ###   ########.fr       */
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
	ERR_PARSE = 1,
	EOF_ = 2
};

# define _EOF_ -1

int				parser(const char *input, t_queue *head);
void			interpret_free(t_interpret *interpret);
int				commands(t_interpret *inter);
int				terminals(t_interpret *inter);
int				eat(t_interpret *inter, const int *types, size_t size);
int				is_type(int cur_type, const int *types, size_t size);
int				parse_error(t_interpret *inter, int out);

#endif
