#include "../../includes/eval.h"

extern char		**g_env;
extern t_queue	*g_queue;

int		init_piper(t_command *command)
{
	int				newpipe[2];
	int				status;
	int				piper_return;
	pid_t			pid;

//	print_s_command(command);
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
		dup2(newpipe[1], 1);
		execve(command->path, command->args, g_env);
		return (0);
	}
	else
	{	
		wait(&status);
		if ((piper_return = recursive_piper(newpipe)) == -1)
			return (-1);
//		else
//			return (0);
//		wait(&status);
//		ft_printf("pid: %d\n", pid);
		// free_stuff
	}
	return (0);
}

int		recursive_piper(int oldpipe[2])
{
	int				newpipe[2];
	int				status;
	t_command		new_command;
	pid_t			pid;
	int				piper_return;
	char			*output_buffer;

	if (g_queue == NULL)
		return (0);
	g_queue = craft_command(&new_command, g_queue);
//	print_s_command(&new_command);
	if (new_command.output_type == PIPE)
	{
		if (pipe(newpipe) == -1)
			perror("pipe");
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		close(oldpipe[1]);
		dup2(oldpipe[0], 0);

		if (new_command.output_type == PIPE) // or redirect
		{
			close(newpipe[0]);
			dup2(newpipe[1], 1);
		}
		execve(new_command.path, new_command.args, g_env);
		return (0);
	}
	else
	{
		close(oldpipe[0]);
		close(oldpipe[1]);
		if (wait(&status) == -1)
		{
			ft_printf("first wait is useless\n");
			perror("wait");
		}
		// IF REDIRECTIONS: JE RECUPERE OUTPUT ET JE LE REPIPE
		if (new_command.output_type == PIPE)
		{
		close(newpipe[1]);
		if (!(output_buffer = read_until_eof(newpipe[0])))
		{
//			ft_printf("cant read\n");
			return (-1);
		}
		//write to redirection files
		ft_printf("output_buffer: %s\n", output_buffer);
		close(newpipe[0]);
		// IF REDIRECTIONS + PIPE
		if (pipe(newpipe) == -1)
			perror("pipe");
//		ft_printf("post_pipe\n");
//		close(newpipe[0]);
		if (write(newpipe[1], output_buffer, ft_strlen(output_buffer)) == -1)
			perror("write");
//		ft_printf("post_write\n");
//		dup2(newpipe[1], 1);
//		write()
//		ft_printf("status pre recursion %d\n", status);
		}
		if (new_command.output_type == PIPE)
		{
//			ft_printf("pre_launch\n");
			// free_stuff
			if ((piper_return = recursive_piper(newpipe)) == -1)
				return (-1);
//			else
//				return (0);
		}
//		if (wait(&status) == -1)
//		{
//			ft_printf("second wait is useless\n");
//			perror("wait");
//		}
//		ft_printf("status post recursion %d\n", status);
//		ft_printf("pid: %d\n", pid);
		// free_stuff
	}
	return (0);
}