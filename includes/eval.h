/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:07:18 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/18 22:54:16 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "types.h"
# include "ft_strings.h"
# include "ft_stdio.h"
# include "lexer.h"

# define READ_FROM_PIPE 1
# define IGNORE_PIPE 0
# define COMMAND_NOT_FOUND 1

typedef struct				s_command
{
	char	*value;
	char	**args;
	int		*output_redirection_files;
	int		*input_redirection_files;
	char	*path;
	int		has_output_redirect;
	int		has_input_redirect;
	int		output_type;
	int		pipefd[2];
}							t_command;

extern char					**g_env;
extern int					g_exitstatus;
extern t_queue				*g_queue;
extern int					g_in_eval;
extern int					g_pid_to_kill;
extern int					g_flawed;

void						init_command(t_command *command);
void						get_sigint_exit_code(int sig);
void						do_nothing(int sig);
void						sigterm_handler(int sig);
char						*get_relative_path(char *value);
void						signal_handler(int sig);
int							run_shell(void);
char						*ft_str_replace_all(char *string, char *to_find,
								char *replacement);
char						*ft_str_replace(char *string, char *to_find,
								char *replacement);
char						*ft_alloncat(char **s1, const char *s2, int len);
int							write_error_free_ret(t_command *command);
void						write_error_nofile(char *command_value);
void						write_error_invalid_command(char *command_value);
int							recursive_piper(int oldpipe[2]);
int							init_piper(t_command *command);
int							appropriate_exit_procedure(t_command *command);
int							free_tab_string_ret_fail(char **string, char
								***tab);
int							free_tab_ret_fail(char ***tab);
int							free_command_ret_fail(t_command *command);
void						free_command(t_command *command);
void						ft_freetab(char ***tab);
int							is_arg(t_queue *queue);
int							craft_command(t_command *command);
int							simple_builtin(t_command *command);
int							is_builtin(char **args);
int							recursive_builtin(t_command *command);
int							*read_redirections_pipe(t_command *command,
								int redirectpipe[2]);
int							*read_redirections_nopipe(t_command *command,
								int pipe[2]);
int							get_input_redirections(t_command *command,
								t_queue *queue);
void						write_redirections(t_command *command,
								char *buffer);
int							get_output_redirections(t_command *command,
								t_queue *queue);
void						ft_print_int_tab(int *tab);
int							*add_to_dynamic_int_array(int **table, int nbr);
int							*ft_int_tab_maker(size_t len);
char						*read_until_eof(int fd);
int							recursive_piper(int oldpipe[2]);
int							init_piper(t_command *command);
int							fork_and_exec(t_command *command);
char						**ft_stabmaker(size_t len);
void						ft_printtab(char **tab);
char						**add_to_dynamic_table(char ***table, char *str);
int							ft_tablen(char **tab);
char						**ft_tab_copy(char ***dst, char **src);
int							eval(t_queue *queue);
void						print_s_command(t_command *command);
char						*ft_strextract(char const *s, char c,
								unsigned int index);
char						*get_path(char *value);
char						**ft_split_tab(char const *s, char c);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
char						*ft_allocat(char **s1, const char *s2);

char						*expand(const char *src);
char						*find_variable(const char *key);
t_spair						get_items(const char *e_var);
char						*get_value(const char *e_var);
char						*get_key(const char *variable);

#endif
