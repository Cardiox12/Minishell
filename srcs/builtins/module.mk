UTILS_DIR = $(BUILTIN_DIR)/utils

SRCS += $(UTILS_DIR)/arrlen.c
SRCS += $(UTILS_DIR)/cd_perror.c

SRCS += $(BUILTIN_DIR)/echo.c
SRCS += $(BUILTIN_DIR)/cd.c
SRCS += $(BUILTIN_DIR)/pwd.c
SRCS += $(BUILTIN_DIR)/env.c
SRCS += $(BUILTIN_DIR)/export.c
SRCS += $(BUILTIN_DIR)/unset.c