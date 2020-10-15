/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:57:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/15 12:15:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static size_t arrlen(char **array)
{
	size_t size;

	size = 0;
	while (array[size] != NULL)
		size++;
	return (size);
}

static void	cd_perror(char *path, int error)
{
	ft_printf("cd: %s: %s\n", strerror(error), path);
}

int		cd(char **args, __unused char **env)
{
	const size_t 	size = arrlen(args);
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
