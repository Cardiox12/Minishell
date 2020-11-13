/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:57:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/13 22:36:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "internals.h"
#include "builtins.h"

static char	*get_home()
{
	char *variable;
	char *home;

	variable = ft_strdup(find_variable("HOME"));
	home = get_value(variable);
	free(variable);
	return (home);
}

int		cd(char **args)
{
	const size_t 	size = string_arr_len(args);
	char			cwd[PATH_MAX + PWD_SIZE + 2];
	char			*path;

	ft_bzero(cwd, PATH_MAX + PWD_SIZE + 2);
	if (size == 1)
		path = get_home();
	else if (size == 2)
		path = ft_strdup(args[1]);
	else
	{
		getcwd(cwd, PATH_MAX);
		return (cd_error("too many argument", FAILURE));
	}
	if (chdir(path) == -1)
		return (cd_perror(path, FAILURE));
	ft_strcpy(cwd, PWD);
	cwd[PWD_SIZE] = '=';
	getcwd(&cwd[PWD_SIZE + 1], PATH_MAX);
	export((string[3]){BUILTINS_EXPORT, cwd, NULL});
	free(path);
	return (SUCCESS);
}
