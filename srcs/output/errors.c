/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:30:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 01:58:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"

static void	print_error(char *bin, char *arg, char *error, int is_str)
{
	ft_putstr_fd(EXE_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(bin, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (is_str)
		ft_putchar_fd('`', STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	if (is_str)
		ft_putchar_fd('\'', STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

void		print_internal_error(char *bin, char *arg, int error, int is_str)
{
	size_t index;

	index = 0;
	while (index < INTERNAL_ERRORS_SIZE)
	{
		if (error == g_internal_errors[index].i_errno)
		{
			print_error(bin, arg, g_internal_errors[index].s_error, is_str);
			return ;
		}
		index++;
	}
}
