/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:28:32 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:43:46 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define NEWLINE '\n'

# define BUFFER_SIZE 100

# define SUCCESS 1
# define ERROR -1
# define END_OF_FILE 0
# define NOT_FOUND -1
# define CONTINUE 2

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "ft_strings.h"

int			set_nl_watch(char *dynamic, int *nl_watch, int bytes);
int			finish_op(char **line, char *buffer, char **dynamic);
int			locate(char *haystack, char needle);
int			get_line(char *buffer, char **dynamic, char **line);
char		*resize(char **dst, size_t start);
char		*append(char **dst, const char *src);
int			get_next_line(int fd, char **line);

#endif
