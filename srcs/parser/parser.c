/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:16:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:12:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "lexer.h"
#include "parser.h"

int	parser(const char *input, t_queue *head)
{
	t_interpret	inter;
	int			out;

	inter = (t_interpret){.input = (char*)input, .tokens = queue_copy(head)};
	inter.current = dequeue(&inter.tokens);
	out = commands(&inter);
	if (out != 0)
		return (parse_error(&inter, out));
	while (TRUE)
	{
		out = terminals(&inter);
		if (out != 0)
			return (parse_error(&inter, out));
		out = commands(&inter);
		if (out != 0)
			return (parse_error(&inter, out));
	}
	interpret_free(&inter);
	return (SUCCESS);
}
