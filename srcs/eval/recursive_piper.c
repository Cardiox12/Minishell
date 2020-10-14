#include "../../includes/eval.h"

extern char		**g_env;
extern t_queue	*g_queue;

int		init_piper(t_command *command)
{
	int				newpipe[2];
	int				inputpipe[2];
	int				status;
	int				piper_return;
	pid_t			pid;
	char			*output_buffer;

	print_s_command(command);
	if (pipe(newpipe) == -1)
		perror("pipe");
//	if (command->has_input_redirect == 1)
//		pipe(inputpipe);
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		// rediriger input ici
		close(newpipe[0]);
		if (command->has_input_redirect == 1)
		{
			pipe(inputpipe);
			read_redirections_nopipe(command, inputpipe);
			dup2(inputpipe[0], 0);
			close(inputpipe[1]);
		}
		dup2(newpipe[1], 1);
		execve(command->path, command->args, g_env);
		return (0);
	}
	else
	{	
		wait(&status);
	
		if (command->has_output_redirect == 1)
		{
			close(newpipe[1]);
			if (!(output_buffer = read_until_eof(newpipe[0])))
				return (-1);
			close(newpipe[0]);
			ft_printf("\n\noutput_buffer: %s\n\n\n", output_buffer);
		//write to redirection files
			write_redirections(command, output_buffer);
			if (pipe(newpipe) == -1)
				perror("pipe");
			if (write(newpipe[1], output_buffer, ft_strlen(output_buffer)) == -1)
				perror("write");
		}
//		if (command->has_input_redirect == 1)
//		{
//			close(inputpipe[0]);
//			close(inputpipe[1]);
//		}
		if ((piper_return = recursive_piper(newpipe)) == -1)
			return (-1);
	}
	return (0);
}

int		recursive_piper(int oldpipe[2])
{
	int				newpipe[2];
	int				status;
	t_command		new_command;
	pid_t			pid;
	int				piper_return;
	char			*output_buffer;

	if (g_queue == NULL)
		return (0);
	g_queue = craft_command(&new_command, g_queue);
	print_s_command(&new_command);
	if (new_command.output_type == PIPE)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		close(oldpipe[1]);
		if (new_command.has_input_redirect)
			read_redirections_pipe(&new_command, &oldpipe);
		dup2(oldpipe[0], 0);
		close(oldpipe[1]);
		if (new_command.output_type == PIPE || new_command.has_output_redirect == 1) // or redirect
		{
			close(newpipe[0]);
			dup2(newpipe[1], 1);
		}
		execve(new_command.path, new_command.args, g_env);
		return (0);
	}
	else
	{
		close(oldpipe[0]);
		close(oldpipe[1]);
		if (wait(&status) == -1)
		{
			ft_printf("first wait is useless\n");
			perror("wait");
		}
		// IF REDIRECTIONS: JE RECUPERE OUTPUT ET JE LE REPIPE
		if (new_command.has_output_redirect == 1)
		{
			close(newpipe[1]);
			if (!(output_buffer = read_until_eof(newpipe[0])))
				return (-1);
		//write to redirection files
			write_redirections(&new_command, output_buffer);
//			ft_printf("\n\noutput_buffer: %s\n", output_buffer);
			close(newpipe[0]);
			if (new_command.output_type == PIPE)
			{
				if (pipe(newpipe) == -1)
					perror("pipe");
				if (write(newpipe[1], output_buffer, ft_strlen(output_buffer)) == -1)
					perror("write");
			}
		}
		if (new_command.output_type == PIPE)
		{
			if ((piper_return = recursive_piper(newpipe)) == -1)
				return (-1);
		}
	}
	return (0);
}