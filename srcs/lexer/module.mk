TOK_DIR	= queue

SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_enqueue.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_dequeue.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_init.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_copy.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_free.c
SRCS	+= $(LEXER_DIR)/$(TOK_DIR)/queue_delete.c

SRCS	+= $(LEXER_DIR)/lexer.c