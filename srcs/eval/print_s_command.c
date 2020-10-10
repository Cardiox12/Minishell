#include "../../includes/eval.h"

void	print_s_command(t_command *command)
{
	ft_printf("\n================== content of t_command =================\n\n");
	ft_printf("value: %s\n", command->value);
	ft_printtab(command->args);
	ft_printf("path: %s\n", command->path);
	if (command->output_type == PIPE)
		ft_printf("output: %s\n", "PIPE");
	if (command->output_type == REDIRECTION)
		ft_printf("output: %s\n", "REDIRECTION");
	if (command->output_type == -1)
		ft_printf("output: %s\n", "STDOUT");
	ft_printf("\n==================          end         =================\n\n");
}