#include "eval.h"

int		free_command_ret_fail(t_command *command)
{
	free_command(command);
	return (-1);
}

int		free_tab_ret_fail(char ***tab)
{
	ft_freetab(tab);
	return (-1);
}

int		free_tab_string_ret_fail(char **string, char ***tab)
{
	ft_strdel(string);
	ft_freetab(tab);
	return (-1);
}