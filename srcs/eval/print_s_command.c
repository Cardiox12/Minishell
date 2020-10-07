#include "../../includes/eval.h"

void	print_s_command(t_command *command)
{
	ft_printf("\n================== content of t_command =================\n\n");
	ft_printf("value: %s\n", command->value);
	ft_printtab(command->args);
	ft_printf("path: %s\n", command->path);
	ft_printf("\n==================          end         =================\n\n");
}