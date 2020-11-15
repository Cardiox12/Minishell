TOK_DIR	= queue

GET_DIR = get

SRCS += $(LEXER_DIR)/$(GET_DIR)/get_argument.c
SRCS += $(LEXER_DIR)/$(GET_DIR)/get_command.c
SRCS += $(LEXER_DIR)/$(GET_DIR)/get_env_variable.c
SRCS += $(LEXER_DIR)/$(GET_DIR)/get_fd.c
SRCS += $(LEXER_DIR)/$(GET_DIR)/get_operator.c
SRCS += $(LEXER_DIR)/$(GET_DIR)/get_option.c
SRCS += $(LEXER_DIR)/$(GET_DIR)/get_pipe.c
SRCS += $(LEXER_DIR)/$(GET_DIR)/get_redirection.c
SRCS += $(LEXER_DIR)/$(GET_DIR)/get_string.c

SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_enqueue.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_dequeue.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_init.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_copy.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_free.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_delete.c

SRCS	+= $(LEXER_DIR)/lexer.c