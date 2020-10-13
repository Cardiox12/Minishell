#include "../../includes/eval.h"

void	write_redirections(t_command *command, char *buffer)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(buffer);
	while (command->output_redirection_files[i] != -1)
	{
		write(command->output_redirection_files[i], buffer, len);
		close(command->output_redirection_files[i]);
//		ft_printf("fd %d closed\n", command->output_redirection_files[i]);
		i++;
	}
}