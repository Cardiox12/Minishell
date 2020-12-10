UTILS_DIR = $(BUILTIN_DIR)/utils
EXPO_DIR  = $(BUILTIN_DIR)/export
EXIT_DIR	= $(BUILTIN_DIR)/exit

SRCS += $(EXIT_DIR)/convert.c

SRCS += $(UTILS_DIR)/arrlen.c
SRCS += $(UTILS_DIR)/cd_perror.c
SRCS += $(UTILS_DIR)/free_spair.c
SRCS += $(UTILS_DIR)/free_env.c
SRCS += $(UTILS_DIR)/find_key.c

SRCS += $(EXPO_DIR)/export_utils.c
SRCS += $(EXPO_DIR)/export_parse.c
SRCS += $(EXPO_DIR)/export_none.c
SRCS += $(EXPO_DIR)/export_key.c
SRCS += $(EXPO_DIR)/export_key_value.c

SRCS += $(BUILTIN_DIR)/echo.c
SRCS += $(BUILTIN_DIR)/cd.c
SRCS += $(BUILTIN_DIR)/pwd.c
SRCS += $(BUILTIN_DIR)/env.c
SRCS += $(BUILTIN_DIR)/export.c
SRCS += $(BUILTIN_DIR)/unset.c
SRCS += $(BUILTIN_DIR)/exit.c
SRCS += $(BUILTIN_DIR)/builtins.c