#include "eval.h"

/*int		setup_pipeline(int len, t_command *command)
{

}*/
int		wait_for_the_kids(pid_t last_pid)
{
	int		status;
	pid_t	pid;

	while ((pid = wait(&status)) != -1)
	{
//		ft_printf("waited pid: %d\n", pid);
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				g_exitstatus = WEXITSTATUS(status);
		}

	}
	return (0);
}

int 	iterative_piper(int pipe_len)
{
	int			i;
	t_command	command;
	pid_t		pid;
	pid_t		last;

	i = 1;
	pipe_len++;
//	ft_printf("pipe_len: %d\n", pipe_len);
	while (g_queue && i < pipe_len)
	{
		if (craft_command(&command) == -1)
			return (-1);
//		print_s_command(&command);
//		i++;
//		ft_printf("i %d\n", i);
		pid = fork();
		if (pid == 0)
		{
//			ft_printf("pid %d created\n", getpid());
			if ((recursive_piper(&command, g_pipe_array[i - 1], g_pipe_array[i])) == -1)
				ft_printf("recursive_failure\n");
//			ft_printf("forked %s doesnt exit\n", command.value);
			exit (1);
		}
		else
		{
			close_pipe(g_pipe_array[i - 1]);
			i++;
			if (i == pipe_len)
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
	int i;
//	t_command	command;

	i = 1;
//	ft_printf("in launch\n");
	if ((pid = fork()) == -1)
		perror("fork");
	if (pid == 0)
	{
		if ((init_piper(g_pipe_array[0], command)) == -1)
		{
			exit(1);
			return (-1);
		}
	}
	else
		iterative_piper(pipe_len);
	return (0);
}

int		initialize_pipeline(t_command *command)
{
	int		pipe_len;

	pipe_len = get_pipeline_len(g_queue);
//	pipe_len = get_pipeline_len(g_queue);
	if (generate_pipe_tab(pipe_len) == -1)
		return (-1);
	if (launch_pipeline(command, pipe_len) == -1)
		return (-1);
	return (0);
}