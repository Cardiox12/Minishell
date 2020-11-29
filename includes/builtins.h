/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:57:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/29 08:20:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H

# include <string.h>
# include <stddef.h>
# include <errno.h>
# include <limits.h>
# include "types.h"
# include "ft_ctypes.h"
# include "ft_stdio.h"
# include "ft_strings.h"
# include "ft_objects.h"
# include "eval.h"

enum	e_builtin_error {
	ERR_BUILTIN_NOT_FOUND = 1
};

typedef int	(*t_builtin_callback)(char**);

typedef struct			s_builtin
{
	char				*func_name;
	t_builtin_callback	callback;
}						t_builtin;

int						echo(char **args);
int						cd(char **args);
int						pwd(char **args);
int						env(char **args);
int						export(char **args);
int						unset(char **args);
int						internal_exit(char **args);
int						builtins_call(t_command *cmd);

int						export_key_value(char *variable);
int						export_key(char *key);
int						export_none(void);
int						parse_by_one(char **args);
int						parse_by_two(char **args);
int						parse_by_three(char **args);
int						is_valid_variable(const char *variable);

# define EXIT_CODE_SYM "?"
# define RAW_ARGUMENT "-n"
# define HOME "~"
# define UNDERSCORE '_'
# define SHLVL_NAME "SHLVL"

# define BUILTINS_SIZE		7
# define BUILTINS_ECHO		"echo"
# define BUILTINS_CD		"cd"
# define BUILTINS_PWD		"pwd"
# define BUILTINS_ENV		"env"
# define BUILTINS_EXPORT	"export"
# define BUILTINS_UNSET		"unset"
# define BUILTINS_EXIT		"exit"

static const t_builtin g_builtins[BUILTINS_SIZE] = {
	{BUILTINS_ECHO, echo},
	{BUILTINS_CD, cd},
	{BUILTINS_PWD, pwd},
	{BUILTINS_ENV, env},
	{BUILTINS_EXPORT, export},
	{BUILTINS_UNSET, unset},
	{BUILTINS_EXIT, internal_exit}
};

#endif
