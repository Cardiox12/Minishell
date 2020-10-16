#ifndef EVAL_H
# define EVAL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "ft_strings.h"
# include "ft_stdio.h"
# include "lexer.h"

typedef struct	s_command
{
	char	*value;
	char	**args;
	int		**redirect_files;
	char	*path;
	int		type_output;
	int		output_type;
	int		input;
	int		fd_in;
	int		fd_out;
	int		pipefd[2];
	char	output_char;
}				t_command;

extern char **g_env;

char	*read_until_eof(int fd);
int		recursive_piper(int oldpipe[2]);
int		init_piper(t_command *command);
t_queue	*craft_command(t_command *command, t_queue *queue);
int		fork_and_exec(char *exec_path, char **exec_args, t_command *command, char *env[]);
char	**ft_stabmaker(size_t len);
void    ft_printtab(char **tab);
char	**add_to_dynamic_table(char ***table, char *str);
int		ft_tablen(char **tab);
char	**ft_tab_copy(char ***dst, char **src);
int		eval(t_queue *queue);
void	print_s_command(t_command *command);
char	*ft_strextract(char const *s, char c, unsigned int index);
char	*get_path(char *value);
char	**ft_split_tab(char const *s, char c);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
char	*ft_allocat(char **s1, const char *s2);

#endif