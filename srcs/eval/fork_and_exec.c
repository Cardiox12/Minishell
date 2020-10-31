#include "../../includes/eval.h"

extern char		**g_env;

int		fork_and_exec(t_command *command)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;
	char	*output_buffer;
	int		inputpipe[2];

//	(void)command; // on verra plus tard comment je le gère
	
	if (command->has_output_redirect == 1)
	{
		if (pipe(pipefd) == -1)
			perror("pipe");
	}
//	if (command->has_input_redirect == 1)
//		pipe(inputpipe);
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
		if (command->has_input_redirect == 1)
		{
			pipe(inputpipe);
			read_redirections_nopipe(command, inputpipe);
			dup2(inputpipe[0], 0);
			close(inputpipe[1]);
		}
//		ft_printf("im here\n");
//		close(inputpipe[1]);
//		close(inputpipe[1]);
		if (execve(command->path, command->args, g_env) == -1)
		{
			ft_printf("minishell: %s: No such file or directory\n", command->value);
			return (-1);
		}
		return (1);
	}
	else
	{
		wait(&status);
//		ft_printf("status %d\n", status);
		if (command->has_output_redirect == 1)
		{
			close(pipefd[1]);
			if (!(output_buffer = read_until_eof(pipefd[0])))
				return (-1);
//			ft_printf("output buffer %s\n", output_buffer);
			write_redirections(command, output_buffer);
			close(pipefd[0]);
		}
//		if (command->has_input_redirect == 1)
//		{
//			close(inputpipe[0]);
//			close(inputpipe[1]);
//		}
//		ft_printf("out of fork and exec\n");
		return (0);
	}	
}
