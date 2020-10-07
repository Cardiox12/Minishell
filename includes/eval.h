#ifndef EVAL_H
# define EVAL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include "ft_strings.h"
# include "ft_stdio.h"
# include "lexer.h"

typedef struct	s_command
{
	char	*value;
	char	**args;
	char	*path;
	int		type_output;
	int		output;
	int		input;
	int		fd_in;
	int		fd_out;
}				t_command;

int							fork_and_exec(char *exec_path, char **exec_args, t_command *command, char *env[]);
char						**ft_stabmaker(size_t len);
void     					ft_printtab(char **tab);
char						**add_to_dynamic_table(char ***table, char *str);
int							ft_tablen(char **tab);
char						**ft_tab_copy(char ***dst, char **src);
int							eval(t_queue *queue);
void						print_s_command(t_command *command);

#endif