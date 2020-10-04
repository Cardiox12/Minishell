# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    module.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 05:01:05 by bbellavi          #+#    #+#              #
#    Updated: 2020/09/29 21:37:19 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR 		+= $(STDIO_DIR)/printf/includes

BUF_API_DIR		= buffer
PARSE_API_DIR	= parser
UTILS_DIR		= utils
ROUTER_DIR		= router
PRINTF_DIR		= printf

INC_FILES		+= $(INC_DIR)/buffer.h
INC_FILES		+= $(INC_DIR)/ft_printf.h
INC_FILES		+= $(INC_DIR)/parser.h
INC_FILES		+= $(INC_DIR)/router.h
INC_FILES		+= $(INC_DIR)/utils.h

SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/ft_printf.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/parse.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/init_state.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/set_flags.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/do_conv.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/set_conv.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/get_conv_length.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/state_active.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/parse_utils_1.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/parse_utils_2.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(PARSE_API_DIR)/pass.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(BUF_API_DIR)/flush_buffer.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(BUF_API_DIR)/init_buffer.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(BUF_API_DIR)/show_buffer.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(BUF_API_DIR)/append_buffer.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(BUF_API_DIR)/append_string_buffer.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(BUF_API_DIR)/append_nbytes_buffer.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(BUF_API_DIR)/is_full.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(UTILS_DIR)/ft_isdigit.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(UTILS_DIR)/ft_issymbol.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(UTILS_DIR)/ft_abs.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(UTILS_DIR)/ft_strchrset.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(UTILS_DIR)/ft_is_negative.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(UTILS_DIR)/ft_is_zero.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(ROUTER_DIR)/ptoa.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(ROUTER_DIR)/itoa.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(ROUTER_DIR)/itohl.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(ROUTER_DIR)/itohu.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(ROUTER_DIR)/utoa.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(ROUTER_DIR)/make_padding.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(ROUTER_DIR)/make_precision.c
SRCS			+= $(STDIO_DIR)/$(PRINTF_DIR)/$(ROUTER_DIR)/make_both.c

CFLAGS			+= -I$(INC_DIR)