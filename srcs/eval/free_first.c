#include "eval.h"

void	free_command(t_command *command)
{
	ft_strdel(&(command->value));
	ft_freetab(&(command->args));
	if (command->has_input_redirect)
		free(command->input_redirection_files);
	if (command->has_output_redirect)
		free(command->output_redirection_files);
	ft_strdel(&(command->path));
}

