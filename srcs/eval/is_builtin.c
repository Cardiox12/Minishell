#include "eval.h"
#include "builtins.h"

int		is_builtin(char **args)
{
	int		index;
	int 	size;

	index = 0;
	size = ft_strlen(*args);
	while (index < BUILTINS_SIZE)
    {
        if (ft_strncmp(g_builtins[index].func_name, *args, size) == 0)
            return (1);
        index++;
    }
    return (0);
}