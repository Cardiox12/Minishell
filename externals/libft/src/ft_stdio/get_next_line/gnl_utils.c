/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 04:11:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			set_nl_watch(char *dynamic, int *nl_watch, int bytes)
{
	if (dynamic && ft_strlen(dynamic) != 0
		&& locate(dynamic, '\n') == NOT_FOUND)
	{
		write(1, "  \b\b", 4);
		*nl_watch = 0;
	}
	else
		*nl_watch = 1;
	if (bytes == 0 && *nl_watch == 1)
		return (-1);
	return (0);
}

int			finish_op(char **line, char *buffer, char **dynamic)
{
	int key_code;

	if ((key_code = get_line(buffer, dynamic, line)) == SUCCESS
			|| key_code == ERROR)
		return (key_code);
	if ((*line = ft_strndup(*dynamic, ft_strlen(*dynamic))) == NULL)
		return (ERROR);
	free(*dynamic);
	*dynamic = NULL;
	return (-286);
}
