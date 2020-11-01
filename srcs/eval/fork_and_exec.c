#include "../../includes/eval.h"

extern char		**g_env;

int		fork_and_exec(t_command *command)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;
	char	*output_buffer;
	int		inputpipe[2];

	if (command->has_output_redirect == 1)
	{
		if (pipe(pipefd) == -1)
			perror("pipe");
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		if (command->has_output_redirect == 1)
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1);
		}
		if (command->has_input_redirect == 1)
		{
			pipe(inputpipe);
			read_redirections_nopipe(command, inputpipe);
			dup2(inputpipe[0], 0);
			close(inputpipe[1]);
		}
		if (execve(command->path, command->args, g_env) == -1)
		{
			ft_printf("minishell: %s: No such file or directory\n", command->value);
			free_command(command);
			exit(1);
//			return (free_command_ret_fail(command));
		}
		return (1);
	}
	else
	{
		if (wait(&status) == -1)
			perror("wait");
		if (command->has_output_redirect == 1)
		{
			close(pipefd[1]);
			if (!(output_buffer = read_until_eof(pipefd[0])))
				return (free_command_ret_fail(command));
			write_redirections(command, output_buffer);
			ft_strdel(&output_buffer);
			close(pipefd[0]);
		}
		free_command(command);
		return (0);
	}	
}
