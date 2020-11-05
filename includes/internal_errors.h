/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_errors.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:12:28 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/04 19:51:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNAL_ERROR_H
# define FT_INTERNAL_ERROR_H

# include "ft_stdio.h"

typedef struct  s_error
{
    int     i_errno;
    char    *s_error;
}               t_error;

# define EXE_NAME "minishell"
# define EXIT_ERR_NON_NUMERIC_ARG 2

# define INTERNAL_ERRORS_SIZE 2

# define ERROR_NOT_VALID_IDENTIFIER 1
# define ERROR_NUMERIC_ARG_REQUIRED 2

static const t_error g_internal_errors[INTERNAL_ERRORS_SIZE] = {
    {ERROR_NOT_VALID_IDENTIFIER, "not a valid identifier"},
    {ERROR_NUMERIC_ARG_REQUIRED, "numeric argument required"}
};

void    print_internal_error(char *bin, char *arg, int error, int is_str);

#endif