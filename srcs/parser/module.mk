INTER_SRCS = $(PARSE_DIR)/interpret
PARSER_SRCS = $(PARSE_DIR)/parser
UTILS_SRCS = $(PARSE_DIR)/utils

SRCS += $(PARSER_SRCS)/commands.c
SRCS += $(PARSER_SRCS)/terminals.c
SRCS += $(PARSER_SRCS)/eat.c

SRCS += $(UTILS_SRCS)/is_type.c
SRCS += $(UTILS_SRCS)/parse_error.c

SRCS += $(PARSE_DIR)/parser.c
SRCS += $(INTER_SRCS)/interpret_free.c