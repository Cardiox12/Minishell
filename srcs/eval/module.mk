STR_DIR = string
VAR_DIR = variables
VAR_UTILS_DIR = utils
ENV_DIR = env

SRCS += $(EVAL_DIR)/$(ENV_DIR)/find_variable.c
SRCS += $(EVAL_DIR)/$(ENV_DIR)/get_items.c
SRCS += $(EVAL_DIR)/$(ENV_DIR)/get_value.c
SRCS += $(EVAL_DIR)/$(ENV_DIR)/get_key.c

SRCS += $(EVAL_DIR)/$(VAR_DIR)/expand.c
SRCS += $(EVAL_DIR)/$(VAR_DIR)/expand2.c
SRCS += $(EVAL_DIR)/$(VAR_DIR)/removal.c
SRCS += $(EVAL_DIR)/$(VAR_DIR)/$(VAR_UTILS_DIR)/utils1.c
SRCS += $(EVAL_DIR)/$(VAR_DIR)/$(VAR_UTILS_DIR)/replace.c

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
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_strreplace.c
SRCS += $(EVAL_DIR)/$(STR_DIR)/ft_strreplace_all.c

SRCS += $(EVAL_DIR)/fork_and_exec.c
SRCS += $(EVAL_DIR)/print_s_command.c
SRCS += $(EVAL_DIR)/path_finder.c
SRCS += $(EVAL_DIR)/recursive_piper.c
SRCS += $(EVAL_DIR)/init_piper.c
SRCS += $(EVAL_DIR)/read_until_eof.c
SRCS += $(EVAL_DIR)/dynamic_int_array.c
SRCS += $(EVAL_DIR)/get_redirection.c
SRCS += $(EVAL_DIR)/write_read_redirections.c
SRCS += $(EVAL_DIR)/recursive_builtin.c
SRCS += $(EVAL_DIR)/is_builtin.c
SRCS += $(EVAL_DIR)/builtin_exec.c
SRCS += $(EVAL_DIR)/craft_command.c
SRCS += $(EVAL_DIR)/ft_freetab.c
SRCS += $(EVAL_DIR)/free_first.c
SRCS += $(EVAL_DIR)/free_ret.c
SRCS += $(EVAL_DIR)/write_on_error.c
SRCS += $(EVAL_DIR)/get_relative_path.c
SRCS += $(EVAL_DIR)/init_command.c
SRCS += $(EVAL_DIR)/get_home.c
SRCS += $(EVAL_DIR)/inc_shlvl.c
SRCS += $(EVAL_DIR)/pipe_setup_utils.c
SRCS += $(EVAL_DIR)/setup_pipeline.c
SRCS += $(EVAL_DIR)/pipeline_utils.c
