/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:57:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/08 23:48:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "internals.h"
#include "builtins.h"

typedef char* t_string;

int			cd(char **args)
{
	const size_t	size = string_arr_len(args);
	char			cwd[PATH_MAX];
	char			old[PATH_MAX];
	char			*path;

	ft_bzero(cwd, PATH_MAX);
	if (size == 1)
		path = get_home();
	else if (size == 2)
		path = ft_strdup(args[1]);
	else
	{
		getcwd(cwd, PATH_MAX);
		return (cd_error("too many argument", FAILURE));
	}
	getcwd(old, PATH_MAX);
	if (chdir(path) == -1)
		return (cd_perror(path, FAILURE));
	getcwd(cwd, PATH_MAX);
	export((t_string[5]){BUILTINS_EXPORT, PWD, "=", cwd, NULL});
	export((t_string[5]){BUILTINS_EXPORT, OLDPWD, "=", old, NULL});
	free(path);
	return (SUCCESS);
}
