/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:39:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:12:49 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

void	ft_putendl_fd(char *s, int fd)
{
	const char *final_s = s;

	while (*s)
		s++;
	write(fd, final_s, s - final_s);
	write(fd, "\n", 1);
}
