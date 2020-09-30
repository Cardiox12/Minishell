/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 00:15:10 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 10:42:53 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTER_H
# define ROUTER_H

# include "buffer.h"
# include "parser.h"

void	ptoa(t_buffer *buffer, long long addr);
void	itoa(t_buffer *buffer, int number);
void	itohl(t_buffer *buffer, unsigned int number);
void	itohu(t_buffer *buffer, unsigned int number);
void	utoa(t_buffer *buffer, unsigned int number);

void	make_padding(t_buffer *buffer, t_state *state, char c);
void	make_conversions_padding(t_buffer *buffer, t_state *state, char c);

void	make_int_precision(t_buffer *buffer, t_state *state);
void	make_string_precision(t_buffer *buffer, t_state *state);
void	make_conversions_precision(t_buffer *buffer, t_state *state);

void	make_string_pp(t_buffer *buffer, t_state *state);
void	make_int_pp(t_buffer *buffer, t_state *state);
void	make_conversions_pp(t_buffer *buffer, t_state *state);

void	make_int_zero_padding(t_buffer *buffer, t_state *state);
void	make_conversions_zero_padding(t_buffer *buffer, t_state *state);

#endif
