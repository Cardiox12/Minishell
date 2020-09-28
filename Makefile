# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 01:50:06 by bbellavi          #+#    #+#              #
#    Updated: 2020/09/29 01:56:03 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

INC_DIR		= includes
SRC_DIR		= srcs

LEXER_DIR	= $(SRC_DIR)/lexer
PARSE_DIR	= $(SRC_DIR)/parser
EVAL_DIR	= $(SRC_DIR)/eval
READ_DIR	= $(SRC_DIR)/reader
OUTPUT_DIR	= $(SRC_DIR)/output

NAME		= minishell

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I$(INC_DIR)