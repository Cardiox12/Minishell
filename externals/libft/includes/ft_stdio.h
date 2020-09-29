/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 09:50:11 by tony              #+#    #+#             */
/*   Updated: 2020/04/30 10:13:11 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_STDIO_H
# define FT_STDIO_H

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif