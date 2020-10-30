#include "../../includes/eval.h"
#include "builtins.h"

extern char		**g_env;
extern t_queue	*g_queue;
int test_file;

/*int		init_piper(t_command *command)
{
	int				newpipe[2];
	int				inputpipe[2];
	int				status;
	int				piper_return;
	pid_t			pid;
	char			*output_buffer;

	if (pipe(newpipe) == -1)
		perror("pipe");
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
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
//		wait(&status);
	
		if (command->has_output_redirect == 1)
		{
			close(newpipe[1]);
			if (!(output_buffer = read_until_eof(newpipe[0])))
				return (-1);
			close(newpipe[0]);
			write_redirections(command, output_buffer);
			if (pipe(newpipe) == -1)
				perror("pipe");
		}
		if ((piper_return = recursive_piper(newpipe)) == -1)
			return (-1);
	}
	wait(&status);
	return (0);
}*/

int		builtin_exec(t_command *command, int *oldpipe[2], int newpipe[2])
{
	int temp_stdout;

	oldpipe[0]++;
	oldpipe[0]--;
	temp_stdout = dup(1);
//	ft_printf("temp stdout : %d\n", temp_stdout);
//	test_file = open("test_output", O_RDWR | O_CREAT | O_TRUNC, 0666);
//	write(test_file, "something", 9);
//	ft_printf("test_file: %d\n", test_file);
//	close((*oldpipe)[1]);
//	if (command->has_input_redirect)
//		read_redirections_pipe(command, oldpipe);
//	dup2((*oldpipe)[0], 0);
//	close((*oldpipe)[1]);
//	ft_printf("in builtin pre pipe\n");
	if (command->output_type == PIPE || command->has_output_redirect == 1) // or redirect
	{
//		close(newpipe[0]);
		dup2(newpipe[1], 1);
	}
//	ft_printf("in builtin post pipe\n");
	builtins_call(command->args);
	if (close(newpipe[1]) == -1)
		perror("close");
//	dup2(1, temp_stdout);
	dup2(temp_stdout, 1);
//	ft_printf("in builtin post pipe\n");
	return (0);
}


int		redirect_handler(int oldpipe[2], int newpipe[2], t_command *command)
{
//	int		status;
//	int		test_file;
	char	*output_buffer;
	
//	test_file = open("test_output", O_RDWR | O_CREAT | O_TRUNC, 0666);
//	ft_printf("test_file: %d\n", test_file);
	close(oldpipe[0]);
	close(oldpipe[1]);
//	ft_printf("in redirect\n");
//	write(test_file, "in redirect", 11);
	if (command->has_output_redirect == 1)
	{
//		if (close(newpipe[1]) == -1)
//			perror("close");
//		write(test_file, "in redirect2", 12);
		if (!(output_buffer = read_until_eof(newpipe[0])))
		{
//			write(test_file, "nothing", 7);
//			ft_printf("nothing to read\n");
//			close(test_file);
			return (-1);
		}
//		write(test_file, "something", 9);
//		close(test_file);
		write_redirections(command, output_buffer);
		close(newpipe[0]);
	}
	return (0);
}

int		recursive_builtin(int oldpipe[2], t_command *command)
{
	int				newpipe[2];
//	int				status;
//	t_command		new_command;
//	pid_t			pid;
	int				piper_return;
//	int				temp_stdout;
//	char			*output_buffer;

//	if (g_queue == NULL)
//		return (0);
//	g_queue = craft_command(&new_command, g_queue);
//	print_s_command(&new_command);
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