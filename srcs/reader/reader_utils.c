/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 04:28:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 05:16:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"
#include <fcntl.h>

int		quotes_util(char **next_command, char **str, int *len)
{
	ft_printf("> ");
	get_next_line(0, next_command);
	*str = ft_join_free_left(str, "\n");
	*str = ft_join_free_left(str, *next_command);
	*len = ft_strlen(*str);
	return (0);
}
