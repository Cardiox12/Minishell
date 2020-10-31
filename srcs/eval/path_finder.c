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

char	*get_path(char *value)
{
	char	**path_tab;
	char	*path_string;
	char	slashed_value[ft_strlen(value) + 2];
	char	*full_path;
	char	*casted_value;

	if (value[0] == '/')
		return (ft_strdup(value));
	ft_bzero(slashed_value, ft_strlen(value) + 2);
	slashed_value[0] = '/';
	casted_value = (char*)slashed_value;
	ft_allocat(&casted_value, value);

	path_string = arraychr(&g_env);
	path_string += 5;

	if (!(path_tab = ft_split_tab(path_string, ':')))
		return (NULL);

	while (*path_tab && !(full_path = check_path(*path_tab, casted_value)))
		path_tab++;
	if (!(*path_tab))
	{
		if (!is_builtin(&value))
			ft_printf("minishell: command not found: %s\n", value);
		return (NULL);
	}
	return(full_path);	
}