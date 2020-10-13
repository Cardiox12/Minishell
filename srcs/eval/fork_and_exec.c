#include "../../includes/eval.h"

extern char		**g_env;

int		fork_and_exec(t_command *command)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;
	char	*output_buffer;

//	(void)command; // on verra plus tard comment je le gère
	
	if (command->has_output_redirect == 1)
	{
		if (pipe(pipefd) == -1)
			perror("pipe");
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		/* free args ? */
		return (1);
	}
	else if (pid == 0)
	{
		if (command->has_output_redirect == 1)
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1);
		}
		if (execve(command->path, command->args, g_env) == -1)
			perror("execve");
		return (1);
	}
	else
	{
		wait(&status);
		if (command->has_output_redirect == 1)
		{
			close(pipefd[1]);
			if (!(output_buffer = read_until_eof(pipefd[0])))
				return (-1);
			write_redirections(command, output_buffer);
			close(pipefd[0]);
		}
		return (0);
	}	
}
