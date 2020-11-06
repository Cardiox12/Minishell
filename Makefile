# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 01:50:06 by tlucille          #+#    #+#              #
#    Updated: 2020/11/06 18:34:31 by tlucille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g #-fsanitize=address

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
BUILTIN_DIR	= $(SRC_DIR)/builtins

LIBFT_NAME	= libft.a
NAME		= minishell

include $(READ_DIR)/module.mk $(LEXER_DIR)/module.mk $(PARSE_DIR)/module.mk $(BUILTIN_DIR)/module.mk $(EVAL_DIR)/module.mk $(OUTPUT_DIR)/module.mk

.PHONY: all clean fclean

all: $(NAME)

$(NAME): build_library $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) main.c $(SRCS) $(LIBFT_NAME) -I$(INC_DIR) -I$(FT_INC_DIR)

build_library:
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/$(LIBFT_NAME) .

clean:
	@rm -f $(LIBFT_NAME)
	@make -C $(LIBFT_DIR) clean 

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@make -C $(LIBFT_DIR) fclean

re: fclean all	
