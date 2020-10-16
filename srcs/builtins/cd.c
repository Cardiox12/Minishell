/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:57:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/17 00:32:20 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"
#include "builtins.h"

int		cd(char **args)
{
	const size_t 	size = string_arr_len(args);
	char			cwd[PATH_MAX];
	char			*path;

	if (size == 2)
		path = args[1];
	else
	{
		getcwd(cwd, PATH_MAX);
		cd_perror(cwd, ENOENT);
		return (ENOENT);
	}
	if (chdir(path) == -1)
	{
		ft_printf("cd: %s: %s\n", strerror(errno), path);
		return (errno);
	}
	return (SUCCESS);
}
