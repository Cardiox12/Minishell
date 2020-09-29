/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:36:08 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 11:37:02 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include "buffer.h"
# include <limits.h>

typedef struct	s_state
{
	char			flags;
	int				conv;
	int				precision;
	int				padding;
	int				conv_length;
	char			specs;
	va_list			args;
}				t_state;

typedef enum	e_flags
{
	F_NEGATIVE = (1U),
	F_ZERO = (1U << 1U),
	F_PRECISION = (1U << 2U),
	F_ASTERISK = (1U << 3U)
}				t_flags;

typedef enum	e_specs
{
	IS_NEGATIVE = (1U),
	IS_ZERO = (1U << 1U),
	PREC_IS_NEG = (1U << 2U)
}				t_specs;

typedef enum	e_conv
{
	C_CHAR = (1U),
	C_STRING = (1U << 1U),
	C_POINTER = (1U << 2U),
	C_INTEGER = (1U << 3U),
	C_UNSIGNED = (1U << 4U),
	C_HEX_LOWER = (1U << 5U),
	C_HEX_UPPER = (1U << 6U),
	C_PERCENT = (1U << 7U)
}				t_conv;

typedef enum	e_symbols
{
	S_CHAR = 'c',
	S_STRING = 's',
	S_POINTER = 'p',
	S_DOUBLE = 'd',
	S_INTEGER = 'i',
	S_UNSIGNED = 'u',
	S_HEX_LOWER = 'x',
	S_HEX_UPPER = 'X',
	S_PERCENT = '%',
	S_NEGATIVE = '-',
	S_ZERO = '0',
	S_PRECISION = '.',
	S_ASTERISK = '*',
	S_SPACE = ' '
}				t_symbols;

# define POINTER_PREFIX "0x"
# define CONVERSIONS "cspdiuxX%"
# define SYMBOLS "cspdiuxX%-0.*"
# define ALL_SYMBOLS "cspdiuxX%-0.*123456789"
# define FLAGS "-0.*"
# define HEX_LOWER_BASE   "0123456789abcdef"
# define HEX_UPPER_BASE   "0123456789ABCDEF"
# define HEX_BASE 16
# define INT_MIN_STR "-2147483648"
# define NULL_MESSAGE "(null)"
# define NULL_LENGTH 6

void			init_state(t_state *state);
char			*ft_parse(t_buffer *buffer, t_state *state, const char *s);
int				state_has_active_flag(t_state *state);
void			set_flags(t_state *state, unsigned char c);
void			do_conv(t_buffer *buffer, t_state *state);
void			set_conv(t_state *state, const char c);
int				get_conv_length(t_state *state);
void			route_flag(t_buffer *buffer, t_state *state);
char			*get_state(t_state *state, const char *s);
void			pass(t_state *state);
void			route_precision_padding(t_buffer *buffer, t_state *state);
void			route_precision(t_buffer *buffer, t_state *state);
void			route_padding(t_buffer *buffer, t_state *state);

#endif
