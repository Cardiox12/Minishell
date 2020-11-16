/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:07:07 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:07:13 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_error(t_interpret *inter, int out)
{
	int	errtok;
	int	index;

	if (out < 0)
	{
		interpret_free(inter);
		return (SUCCESS);
	}
	index = inter->current->token.index;
	errtok = inter->input[index];
	ft_putstr_fd(EXE_NAME, STDERR_FILENO);
	ft_putchar_fd(':', STDERR_FILENO);
	ft_putchar_fd(' ', STDERR_FILENO);
	ft_putstr_fd(ERROR_SYNTAX, STDERR_FILENO);
	ft_putchar_fd(' ', STDERR_FILENO);
	ft_putchar_fd('`', STDERR_FILENO);
	ft_putchar_fd(errtok, STDERR_FILENO);
	if (errtok == inter->input[index + 1])
		ft_putchar_fd(errtok, STDERR_FILENO);
	ft_putchar_fd('\'', STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	interpret_free(inter);
	return (out);
}
