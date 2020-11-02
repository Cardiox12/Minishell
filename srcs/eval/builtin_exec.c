#include "../../includes/eval.h"
#include "builtins.h"

extern t_queue	*g_queue;

int		simple_builtin_exec(t_command *command, int newpipe[2])
{
	int temp_stdout;

	temp_stdout = dup(1);
	if (command->has_output_redirect == 1) // or redirect
		dup2(newpipe[1], 1);
	builtins_call(command->args);
	if (command->has_output_redirect == 1)
	{
		if (close(newpipe[1]) == -1)
			perror("close");
	}
	dup2(temp_stdout, 1);
	return (0);
}


int		simple_redirect_handler(int newpipe[2], t_command *command)
{
	char	*output_buffer;
	
	if (command->has_output_redirect == 1)
	{
		if (close(newpipe[1]) == -1)
			perror("close");
		if (!(output_buffer = read_until_eof(newpipe[0])))
		{
			close(newpipe[0]);
			return (-1);
		}
		write_redirections(command, output_buffer);
	}
	return (0);
}

int		simple_builtin(t_command *command)
{
	int				newpipe[2];
	if (command->has_output_redirect == 1)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	simple_builtin_exec(command, newpipe);
	if (simple_redirect_handler(newpipe, command) == -1)
		return (free_command_ret_fail(command));
	return (0);
}