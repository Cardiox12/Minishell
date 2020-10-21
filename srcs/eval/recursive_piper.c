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
		wait(&status);
	
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
	return (0);
}

int		child_exec(t_command *command, int *oldpipe[2], int newpipe[2])
{
	close((*oldpipe)[1]);
	if (command->has_input_redirect)
		read_redirections_pipe(command, oldpipe);
	dup2((*oldpipe)[0], 0);
	close((*oldpipe)[1]);
	if (command->output_type == PIPE || command->has_output_redirect == 1) // or redirect
	{
		close(newpipe[0]);
		dup2(newpipe[1], 1);
	}
	execve(command->path, command->args, g_env);
	return (0);
}


int		parent_exec(int oldpipe[2], int newpipe[2], t_command *command)
{
	int		status;
	char	*output_buffer;
	
	close(oldpipe[0]);
	close(oldpipe[1]);
	if (wait(&status) == -1)
		perror("wait");
	if (command->has_output_redirect == 1)
	{
//		ft_printf("here\n");
//		ft_printf("newpipe 1%d\n", newpipe[1]);
		close(newpipe[1]);
//		ft_printf("here2\n");
		if (!(output_buffer = read_until_eof(newpipe[0])))
			return (-1);
//		ft_printf("here3\n");
		write_redirections(command, output_buffer);
		close(newpipe[0]);
/*		if (command->output_type == PIPE)
		{
			if (pipe(*newpointer) == -1)
				perror("pipe");
		}*/
	}
	return (0);
}

int		recursive_piper(int oldpipe[2])
{
	int				newpipe[2];
//	int				status;
	t_command		new_command;
	pid_t			pid;
	int				piper_return;
//	char			*output_buffer;

	if (g_queue == NULL)
		return (0);
	g_queue = craft_command(&new_command, g_queue);
//	print_s_command(&new_command);
	if (new_command.output_type == PIPE || new_command.has_output_redirect == 1)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
		return (child_exec(&new_command, (int**)&oldpipe, newpipe));
	else
	{
//		ft_print_int_tab(newpipe);
		if (parent_exec(oldpipe, newpipe, &new_command) == -1)
			return (-1);
/*		close(oldpipe[0]);
		close(oldpipe[1]);
		if (wait(&status) == -1)
			perror("wait");
		if (new_command.has_output_redirect == 1)
		{
			close(newpipe[1]);
			if (!(output_buffer = read_until_eof(newpipe[0])))
				return (-1);
			write_redirections(&new_command, output_buffer);
			close(newpipe[0]);*/
		if (new_command.has_output_redirect && new_command.output_type == PIPE)
		{
			if (pipe(newpipe) == -1)
				perror("pipe");
		}
		if (new_command.output_type == PIPE)
		{
			if ((piper_return = recursive_piper(newpipe)) == -1)
				return (-1);
		}
	}
	return (0);
}