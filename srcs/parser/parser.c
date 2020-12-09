/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:16:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 00:09:56 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "lexer.h"
#include "parser.h"
#include "eval.h"

int	check_syntax(const char *input, t_queue *head)
{
	t_interpret	inter;
	int			out;

	inter = (t_interpret){.input = (char*)input, .tokens = queue_copy_all(head)};
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

int	parser(const char *line)
{
	t_queue	*tokens;
	int		status;

	status = SUCCESS;
	g_quote_parity_error = 0;
	tokens = get_tokens(line);
	if (g_quote_parity_error)
	{
		ft_putstr_fd("minishell: Error quote is not closed\n", 2);
		status = FAILURE;
	}
	else if (check_syntax(line, tokens) > 0)
	{
		g_exitstatus = 2;
		status = FAILURE;
	}
	queue_delete(&tokens);
	return (status);
}
