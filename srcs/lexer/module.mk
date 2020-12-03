TOK_DIR	= queue

GET_DIR = get
CBK_DIR = callbacks
UTL_DIR = utils

SRCS += $(LEXER_DIR)/$(UTL_DIR)/is_bash_charset.c
SRCS += $(LEXER_DIR)/$(UTL_DIR)/is_redirect.c
SRCS += $(LEXER_DIR)/$(UTL_DIR)/is_sep.c
SRCS += $(LEXER_DIR)/$(UTL_DIR)/quote_extract.c
SRCS += $(LEXER_DIR)/$(UTL_DIR)/is_escaped.c
SRCS += $(LEXER_DIR)/$(UTL_DIR)/quotes/is_quote_closed.c
SRCS += $(LEXER_DIR)/$(UTL_DIR)/quotes/remove_quotes.c

SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_argument.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_command.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_default.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_env_variable.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_fd.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_operator.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_option.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_pipe.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_redirection.c
SRCS += $(LEXER_DIR)/$(CBK_DIR)/callback_string.c

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
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_pop_last.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_init.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_copy.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_free.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_last.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_delete.c

SRCS	+= $(LEXER_DIR)/lexer.c