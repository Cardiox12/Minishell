UTILS_DIR = $(BUILTIN_DIR)/utils

SRCS += $(UTILS_DIR)/arrlen.c
SRCS += $(UTILS_DIR)/cd_perror.c
SRCS += $(UTILS_DIR)/free_spair.c
SRCS += $(UTILS_DIR)/free_env.c

SRCS += $(BUILTIN_DIR)/echo.c
SRCS += $(BUILTIN_DIR)/cd.c
SRCS += $(BUILTIN_DIR)/pwd.c
SRCS += $(BUILTIN_DIR)/env.c
SRCS += $(BUILTIN_DIR)/export.c
SRCS += $(BUILTIN_DIR)/unset.c
SRCS += $(BUILTIN_DIR)/exit.c
SRCS += $(BUILTIN_DIR)/builtins.c