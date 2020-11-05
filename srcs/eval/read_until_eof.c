/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_until_eof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:25:08 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:25:09 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

#define BUF_SIZE 4

char	*read_until_eof(int fd)
{
	char	*total_data;
	char	buffer[BUF_SIZE + 1];
	int		ret;

	if ((ret = read(fd, buffer, BUF_SIZE)) == -1)
		perror("read");
//	ft_printf("ret read: %d\n", ret);
//	write(1, buffer, 4);
	buffer[ret] = '\0';
	if (!(total_data = ft_strdup(buffer)))
		return (NULL);
	while ((ret = read(fd, buffer, BUF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!(total_data = ft_join_free_left(&total_data, buffer)))
			return (NULL);
	}
	return (total_data);
}
