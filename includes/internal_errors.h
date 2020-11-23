/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_errors.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:12:28 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 11:12:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNAL_ERRORS_H
# define FT_INTERNAL_ERRORS_H

# include "ft_stdio.h"

typedef struct	s_error
{
	int			i_errno;
	char		*s_error;
}				t_error;

# define EXE_NAME "minishell"
# define EXIT_ERR_NON_NUMERIC_ARG 2

# define INTERNAL_ERRORS_SIZE 2

# define ERROR_NOT_VALID_IDENTIFIER 1
# define ERROR_NUMERIC_ARG_REQUIRED 2

# define ERROR_SYNTAX "syntax error near unexpected token"

static const t_error g_internal_errors[INTERNAL_ERRORS_SIZE] = {
	{ERROR_NOT_VALID_IDENTIFIER, "not a valid identifier"},
	{ERROR_NUMERIC_ARG_REQUIRED, "numeric argument required"}
};

enum	e_internals_errors
{
	ERR_MALLOC_FAILED = -1
};

void			print_internal_error(char *bin, char *arg, int error, int str);

#endif
