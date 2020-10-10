#include "../../includes/eval.h"

extern char		**g_env;

t_queue		*init_piper(t_queue *queue, t_command *command)
{
	int				newpipe[2];
	int				status;
	pid_t			pid;

	print_s_command(command);
	if (pipe(newpipe) == -1)
		perror("pipe");
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (NULL);
	}
	if (pid == 0)
	{
		close(newpipe[0]);
		dup2(newpipe[1], 1);
		execve(command->path, command->args, g_env);
	}
	else
	{	
		if (!(recursive_piper(queue, newpipe)))
			return (NULL);
		wait(&status);
		// free_stuff
	}
	return (NULL);
}

t_queue		*recursive_piper(t_queue *queue, int oldpipe[2])
{
	int				newpipe[2];
	int				status;
	t_command		new_command;
	pid_t			pid;

	ft_printf("aqui\n");
	if (queue == NULL)
		return (NULL);
	queue = craft_command(&new_command, queue);
	print_s_command(&new_command);
	if (new_command.output_type == PIPE)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (NULL);
	}
	if (pid == 0)
	{
		close(oldpipe[1]);
		dup2(oldpipe[0], 0);

		if (new_command.output_type == PIPE)
		{
			close(newpipe[0]);
			dup2(newpipe[1], 1);
		}
		execve(new_command.path, new_command.args, g_env);
	}
	else
	{
		close(oldpipe[0]);
		close(oldpipe[1]);
		if (new_command.output_type == PIPE)
		{
			if (!(recursive_piper(queue, newpipe)))
				return (NULL);
		}
		wait(&status);
		// free_stuff
	}
	return (NULL);
}