#include "eval.h"

int		wait_for_the_kids(pid_t last_pid)
{
	int		status;
	pid_t	pid;

	free_pipe_tab();
	while ((pid = wait(&status)) != -1)
	{
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				g_exitstatus = WEXITSTATUS(status);
		}
	}
	return (0);
}

int		iterative_child_exec(int i, t_command *command)
{
	close_useless_pipes(i - 1, i, i);
	if ((recursive_piper(command, g_pipe_array[i - 1], g_pipe_array[i])) == -1)
		ft_printf("recursive_failure\n");
	exit(1);
}

int		iterative_piper(int pipeline_len)
{
	int			i;
	t_command	command;
	pid_t		pid;
	pid_t		last;

	i = 1;
	while (g_queue && i < pipeline_len)
	{
		if (craft_command(&command) == -1)
			return (-1);
		pid = fork();
		if (pid == 0)
			iterative_child_exec(i, &command);
		else
		{
			free_command(&command);
			close_pipe(g_pipe_array[i - 1]);
			i++;
			if (i == pipeline_len)
				last = pid;
		}
	}
	close_pipe(g_pipe_array[i - 1]);
	wait_for_the_kids(last);
	return (0);
}

int		launch_pipeline(t_command *command, int pipe_len)
{
	pid_t pid;

	if ((pid = fork()) == -1)
		perror("fork");
	if (pid == 0)
	{
		close_useless_pipes(-1, 0, 0);
		if ((init_piper(g_pipe_array[0], command)) == -1)
		{
			exit(1);
			return (-1);
		}
	}
	else
	{
		free_command(command);
		iterative_piper(pipe_len + 1);
	}
	return (0);
}

int		initialize_pipeline(t_command *command)
{
	int		pipe_len;

	pipe_len = get_pipeline_len(g_queue);
	if (generate_pipe_tab(pipe_len) == -1)
		return (-1);
	if (launch_pipeline(command, pipe_len) == -1)
		return (-1);
	return (0);
}
