#include "../../includes/eval.h"

int		fork_and_exec(char *exec_path, char **exec_args, t_command *command, char *env[])
{
	pid_t	pid;
	int		status;

	(void)command; // on verra plus tard comment je le gère
	
	if ((pid = fork()) == -1)
	{
		perror("fork");
		/* free args ? */
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(exec_path, exec_args, env) == -1)
			perror("");
		return (1);
	}
	else
	{
		wait(&status);
		return (0);
	}	
}
