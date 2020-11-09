#include <limits.h>
#include <unistd.h>
#include "eval.h"

char	*get_relative_path(char *value)
{
	char	cwd[PATH_MAX];
	char	*cwd_slashed;
	char	*full_relative_path;

	getcwd(cwd, PATH_MAX);
	if (!(cwd_slashed = ft_strjoin(cwd, "/")))
		return (NULL);
	if (!(full_relative_path = ft_str_replace(value, ".", cwd_slashed)))
		return (NULL);
	return (full_relative_path);
}