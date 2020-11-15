/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:22:45 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:22:47 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "builtins.h"

void	error_quit(char *quit_message, char **to_free)
{
	ft_printf("%s\n", quit_message);
	ft_strdel(to_free);
	exit(EXIT_FAILURE);
}

char	*arraychr(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		if (ft_strncmp("PATH=", (*tab)[i], 5) == 0)
			return ((*tab)[i]);
		i++;
	}
	return (NULL);
}

char	*check_path(char *path, char *slashed_value)
{
	char		full_path[ft_strlen(path) + ft_strlen(slashed_value) + 1];
	struct stat	s_stat;
	char		*casted_path;

	casted_path = (char*)full_path;
	ft_bzero(casted_path, ft_strlen(path) + ft_strlen(slashed_value) + 1);
	ft_allocat(&casted_path, path);
	ft_allocat(&casted_path, slashed_value);
	if (stat(casted_path, &s_stat) == -1)
		return (NULL);
	else
		return (ft_strdup(full_path));
}

char	*get_path_finalize(char *full_path, char *casted_value, char *value)
{
	char	**path_tab;
	char	**tab_temp;
	char	*absolute_path;

	if (!(path_tab = ft_split_tab(full_path, ':')))
		return (NULL);
	tab_temp = path_tab;
	while (*path_tab && !(absolute_path = check_path(*path_tab, casted_value)))
		path_tab++;
	if (!(*path_tab))
	{
		if (!is_builtin(&value))
		{
			ft_freetab(&tab_temp);
			return (ft_strdup(value));
		}
		ft_freetab(&tab_temp);
		return (NULL);
	}
	ft_freetab(&tab_temp);
	return (absolute_path);
}

char	*get_path(char *value)
{
	char	slashed_value[ft_strlen(value) + 2];
	char	*full_path;
	char	*casted_value;

	if (value[0] == '/')
		return (ft_strdup(value));
	if (ft_strchr(value, '/') != NULL)
		return (get_relative_path(value));
	if (value[0] == '\0')
		return (ft_strdup("\b \b"));
	ft_bzero(slashed_value, ft_strlen(value) + 2);
	slashed_value[0] = '/';
	casted_value = (char*)slashed_value;
	ft_allocat(&casted_value, value);
	if (!(full_path = arraychr(&g_env)))
		return (ft_strdup(value));
	full_path += 5;
	return (get_path_finalize(full_path, casted_value, value));
}
