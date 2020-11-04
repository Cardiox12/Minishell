/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:30:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/04 19:50:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"

void    print_internal_error(char *bin, char *arg, int error, int is_str)
{
    size_t index;

    index = 0;
    while (index < INTERNAL_ERRORS_SIZE)
    {
        if (error == g_internal_errors[index].i_errno)
        {
            if (is_str)
            {
                ft_printf("%s: %s: `%s': %s\n", EXE_NAME, bin, arg, 
                g_internal_errors[index].s_error);
            }
            else
            {
                ft_printf("%s: %s: %s: %s\n", EXE_NAME, bin, arg, 
                g_internal_errors[index].s_error);
            }
            return ;
        }
        index++;
    }
}