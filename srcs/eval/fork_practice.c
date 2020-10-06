#include "libft/ft_libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
	pid_t		pid;
	int			status;
// 	int			pipefd_dad[2];
//	int			pipefd_son[2];
	int			pipefd[2];
	int			pipe_return;
	char		buffer[100];
	char		test_string[] = "hello";

	ft_bzero(buffer, 100);
	if (argc > 1)
    {
//		pipefd[1] = 1;
//		pipefd[0] = 0;
		if (pipe(pipefd) == -1)
			perror("pipe");
		if ((pid = fork()) == -1)
        {
        	perror("fork");
        	return 1;
        }
      /* Si pid == 0, alors on est dans le process fils. */
		else if (pid == 0)
        {	
//			pipefd_son[1] = 1;
//			pipefd_son[0] = 0;
			close(pipefd[0]);
//			pipefd[1] = 1;
//			if (execve(argv[1], argv + 1, env) == -1)
// 	           perror("execve");
			write(pipefd[1], "hello", 5);
			return 1; /* On termine le fils même si execve fail parce qu'on veut voir que le pid du pere*/
        }
      /* Sinon, dans le pere. */
		else
		{
			close(pipefd[1]);
			read(pipefd[0], buffer, 100);
			wait(&status); /* Oui, il faudrait vérifier la valeur de retour... */
		}

  		printf("My pid is: %d\n", getpid());
 		ft_printf("buffer: %s", buffer);
	}

  return 0;
}