STR_DIR = string
VAR_DIR = variables
ENV_DIR = env

SRCS += $(EVAL_DIR)/$(ENV_DIR)/find_variable.c
SRCS += $(EVAL_DIR)/$(ENV_DIR)/get_items.c
SRCS += $(EVAL_DIR)/$(ENV_DIR)/get_value.c

SRCS += $(EVAL_DIR)/$(VAR_DIR)/expand.c

SRCS += $(EVAL_DIR)/dynamic_table.c
SRCS += $(EVAL_DIR)/eval_master.c

SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_printtab.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_stabmaker.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_tab_copy.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_tablen.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_strextract.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_strnew.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_split_tab.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_strdel.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_allocat.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_int_tab_maker.c

SRCS += $(EVAL_DIR)/fork_and_exec.c
SRCS += $(EVAL_DIR)/print_s_command.c
SRCS += $(EVAL_DIR)/path_finder.c
SRCS += $(EVAL_DIR)/recursive_piper.c
SRCS += $(EVAL_DIR)/read_until_eof.c
SRCS += $(EVAL_DIR)/dynamic_int_array.c
SRCS += $(EVAL_DIR)/get_redirection.c
SRCS += $(EVAL_DIR)/write_read_redirections.c
SRCS += $(EVAL_DIR)/recursive_builtin.c
SRCS += $(EVAL_DIR)/is_builtin.c
SRCS += $(EVAL_DIR)/builtin_exec.c
