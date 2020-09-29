# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 01:50:06 by bbellavi          #+#    #+#              #
#    Updated: 2020/09/29 02:13:38 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

EXT_DIR		= externals
INC_DIR		= includes
SRC_DIR		= srcs

LIBFT_DIR	= $(EXT_DIR)/libft
FT_INC_DIR	= $(LIBFT_DIR)/includes

LEXER_DIR	= $(SRC_DIR)/lexer
PARSE_DIR	= $(SRC_DIR)/parser
EVAL_DIR	= $(SRC_DIR)/eval
READ_DIR	= $(SRC_DIR)/reader
OUTPUT_DIR	= $(SRC_DIR)/output

LIBFT_NAME	= libft.a
NAME		= minishell

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(SRCS) | build_library
	@$(CC) $(CFLAGS) -o $(NAME) main.c $(SRCS) $(LIBFT_NAME) -I$(INC_DIR) -I$(FT_INC_DIR)

build_library:
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/$(LIBFT_NAME) .

clean:
	@rm -f $(LIBFT_NAME)
	@make -C $(LIBFT_DIR) clean 

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all	
