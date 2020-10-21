#include "../../includes/eval.h"

void	write_redirections(t_command *command, char *buffer)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(buffer);
	while (command->output_redirection_files[i + 1] != -1)
	{
		close(command->output_redirection_files[i]);
//		ft_printf("fd %d closed\n", command->output_redirection_files[i]);
		i++;
	}
//	ft_printf("output_tab[%d] : %d\n", i, command->output_redirection_files[i]);
//	ft_printf("buffer : %s\n", buffer);
//	print_s_command(command);
	write(command->output_redirection_files[i], buffer, len);
	close(command->output_redirection_files[i]);
}

int		*read_redirections_pipe(t_command *command, int *oldpipe[2])
{
//	int		len;
	int		i;
	char	*buffer;
//	char	*input;
//	int		newpipe[2];

	i = 0;
//	if (!(input = read_until_eof((*oldpipe)[0])))
//		return ((void*)0);
//	ft_printf("piped input %s\n", input);
	close((*oldpipe)[0]);
	pipe(*oldpipe);
//	write((*oldpipe)[1], input, ft_strlen(input));
//	ft_strdel(&input);
	while (command->input_redirection_files[i + 1] != -1)
	{
//		if (!(input = ft_join_free_left(&input, buffer)))
//			return ((void*)0);
//		ft_strdel(&buffer);
		close(command->input_redirection_files[i]);
		i++;
	}
	if (!(buffer = read_until_eof(command->input_redirection_files[i])))
		return ((void*)0);
	write((*oldpipe)[1], buffer, ft_strlen(buffer));
	close(command->input_redirection_files[i]);
	return ((void*)0);
}

int		*read_redirections_nopipe(t_command *command, int pipe[2])
{
//	int		len;
	int		i;
	char	*buffer;
//	char	*input;

	i = 0;
/*	if (!(input = read_until_eof(command->input_redirection_files[i])))
		return ((void*)0);
	i++;
	write(pipe[1], input, ft_strlen(input));
	ft_strdel(&input);*/
	while (command->input_redirection_files[i + 1] != -1)
	{
//		if (!(input = ft_join_free_left(&input, buffer)))
//			return ((void*)0);
	//	ft_strdel(&buffer);
		close(command->input_redirection_files[i]);
		i++;
	}
	if (!(buffer = read_until_eof(command->input_redirection_files[i])))
		return ((void*)0);
	write(pipe[1], buffer, ft_strlen(buffer));
	close(command->input_redirection_files[i]);
	return ((void*)0);
}