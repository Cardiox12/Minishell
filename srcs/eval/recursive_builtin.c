#include "../../includes/eval.h"
#include "builtins.h"

extern char		**g_env;
extern t_queue	*g_queue;
int test_file;


int		builtin_exec(t_command *command, int *oldpipe[2], int newpipe[2])
{
	int temp_stdout;

	oldpipe[0]++;
	oldpipe[0]--;
	temp_stdout = dup(1);
	if (command->output_type == PIPE || command->has_output_redirect == 1) // or redirect
	{
		dup2(newpipe[1], 1);
	}
	builtins_call(command->args);
	if (close(newpipe[1]) == -1)
		perror("close");
	dup2(temp_stdout, 1);
	return (0);
}


int		redirect_handler(int oldpipe[2], int newpipe[2], t_command *command)
{
	char	*output_buffer;
	
	close(oldpipe[0]);
	close(oldpipe[1]);
	if (command->has_output_redirect == 1)
	{
		if (!(output_buffer = read_until_eof(newpipe[0])))
		{
			return (-1);
		}
		write_redirections(command, output_buffer);
		close(newpipe[0]);
	}
	return (0);
}

int		recursive_builtin(int oldpipe[2], t_command *command)
{
	int				newpipe[2];
	int				piper_return;

	if (command->output_type == PIPE || command->has_output_redirect == 1)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	builtin_exec(command, (int**)&oldpipe, newpipe);
	if (redirect_handler(oldpipe, newpipe, command) == -1)
		return (-1);
	if (command->has_output_redirect && command->output_type == PIPE)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if (command->output_type == PIPE)
	{
		if ((piper_return = recursive_piper(newpipe)) == -1)
			return (-1);
	}
	return (0);
}