#include "eval.h"
#include "builtins.h"

extern t_queue	*g_queue;

int		init_return_parent(int newpipe[2], t_command *command)
{
	int		status;
	char	*output_buffer;

	if (command->has_output_redirect == 1)
	{
		close(newpipe[1]);
		if (!(output_buffer = read_until_eof(newpipe[0])))
			return (free_command_ret_fail(command));
		close(newpipe[0]);
		write_redirections(command, output_buffer);
		if (pipe(newpipe) == -1)
			perror("pipe");
		ft_strdel(&output_buffer);
	}
	if ((recursive_piper(newpipe)) == -1)
		return (free_command_ret_fail(command));
	wait(&status);
	free_command(command);
	return (0);
}

int 	init_child_exec(int inputpipe[2], int newpipe[2], t_command *command)
{
	if (command->has_input_redirect == 1)
	{
		read_redirections_nopipe(command, inputpipe);
		dup2((inputpipe)[0], 0);
		close((inputpipe)[1]);
	}
	dup2(newpipe[1], 1);
	if (execve(command->path, command->args, g_env) == -1)
	{
		ft_printf("minishell: %s: No such file or directory\n", command->value);
		free_command(command);
		exit(1);
//		return (free_command_ret_fail(command));
	}
	return (0);
}

int		init_piper(t_command *command)
{
	int				newpipe[2];
	int				inputpipe[2];
//	int				status;
//	int				piper_return;
	pid_t			pid;
//	char			*output_buffer;

	ft_bzero(inputpipe, 2);
	if (pipe(newpipe) == -1)
		perror("pipe");
	if (is_builtin(command->args))
		return (recursive_builtin(newpipe, command));
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (free_command_ret_fail(command));
	}
	if (pid == 0)
	{
		close(newpipe[0]);
		if (command->has_input_redirect == 1)
			pipe(inputpipe);
		if (init_child_exec(inputpipe, newpipe, command) == -1)
			return (-1);
	}
	else
		return(init_return_parent(newpipe, command));
	ft_printf("should not appear\n");
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
	if (execve(command->path, command->args, g_env) == -1)
	{
		ft_printf("minishell: %s: No such file or directory\n", command->value);
		free_command(command);
		exit(1);
//			return (free_command_ret_fail(command));
	}
	return (0);
}


int		parent_exec(int oldpipe[2], int newpipe[2], t_command *command)
{
	char	*output_buffer;
	
	close(oldpipe[0]);
	close(oldpipe[1]);
	if (command->has_output_redirect == 1)
	{
		close(newpipe[1]);
		if (!(output_buffer = read_until_eof(newpipe[0])))
			return (free_command_ret_fail(command));
		write_redirections(command, output_buffer);
		close(newpipe[0]);
		ft_strdel(&output_buffer);
	}
	return (0);
}

int		recur_parent_exec(int oldpipe[2], int newpipe[2], t_command *new_command)
{
	int		status;

	if (parent_exec(oldpipe, newpipe, new_command) == -1)
		return (-1);
	if (new_command->has_output_redirect && new_command->output_type == PIPE)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if (new_command->output_type == PIPE)
	{
		if ((recursive_piper(newpipe)) == -1)
			return (free_command_ret_fail(new_command));
	}
	if (wait(&status) == -1)
		perror("wait");
	free_command(new_command);
	return (0);	
}

int		recursive_piper(int oldpipe[2])
{
	int				newpipe[2];
//	int				status;
	t_command		new_command;
	pid_t			pid;
//	int				piper_return;

	if (g_queue == NULL)
		return (0);
	if (craft_command(&new_command) == -1)
		return (-1);
	if (is_builtin(new_command.args))
		return (recursive_builtin(oldpipe, &new_command));
	if (new_command.output_type == PIPE || new_command.has_output_redirect == 1)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (free_command_ret_fail(&new_command));
	}
	else if (pid == 0)
		return (child_exec(&new_command, (int**)&oldpipe, newpipe));
	else
		return (recur_parent_exec(oldpipe, newpipe, &new_command));
}