/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:13:31 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:44:27 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 64

typedef struct	s_buffer
{
	char		buffer[BUFFER_SIZE];
	int			cursor;
	int			accumulator;
}				t_buffer;

void			init_buffer(t_buffer *buffer);
void			show_buffer(t_buffer *buffer);
int				buffer_is_full(t_buffer *buffer);
void			append_to_buffer(t_buffer *buffer, char c);
void			append_string_to_buffer(t_buffer *buffer, const char *s);
void			append_nchar_to_buffer(t_buffer *buffer, const char *s,
				size_t n);
void			flush_buffer(t_buffer *buffer);

#endif
