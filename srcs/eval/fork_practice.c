#include "libft/ft_libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

static char                     **ft_stabmaker(size_t len)
{
        char                    **stab;
        unsigned int    i;

        i = 0;
        if (!(stab = (char**)malloc(sizeof(char*) * (len + 1))))
                return (NULL);
        while (i < len)
        {
                stab[i] = 0;
                i++;
        }
        stab[i] = 0;
        return (stab);
}

char	*read_until_eof(int fd)
{
	char	*total_data;
	char	buffer[100];

	ft_bzero(buffer, 100);
	read(fd, buffer, 99);
	if (!(total_data = ft_strdup(buffer)))
		return (NULL);
	while (read(fd, buffer, 99) > 0)
	{
		if (!(total_data = ft_join_free_left(&total_data, buffer)))
			return (NULL);
		ft_bzero(buffer, 100);	
	}
	return (total_data);
}

char	**craft_arg(int fd)
{
	char	**arg_tab;

	if (!(arg_tab = ft_stabmaker(2)))
		return (NULL);
	if (!(arg_tab[0] = ft_strdup("-l")))
		return (NULL);
//	if (!(arg_tab[1] = read_until_eof(fd)))
//		return (NULL);
	return (arg_tab);
}

int		fork_and_exec(char *exec_path, char **exec_args, int io_fds[2], char *env[])
{
	pid_t	pid;
	int		status;

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

int main(int argc, char *argv[], char *env[])
{
	pid_t		pid;
	int			status;
	char		**arg_tab;
// 	int			pipefd_dad[2];
//	int			pipefd_son[2];
	int			pipefd[2];
	int			pipe_return;
	char		buffer[100];
	char		*piped_output;

//	ft_printtab(env);
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
			if (dup2(pipefd[1], 1) == -1)
	           perror("dup2");
//			close(pipefd[1]);
			if (execve(argv[1], argv + 1, env) == -1)
	           perror("execve");
//			write(pipefd[1], "hello", 5);
//			write(pipefd[1], "hello", 5);
			close(pipefd[1]);
			return 1; /* On termine le fils même si execve fail parce qu'on veut voir que le pid du pere*/
        }
      /* Sinon, dans le pere. */
		else
		{
			/* faudrait faire une fonction "read until EOF" */
			close(pipefd[1]);
//			if (!(piped_output = read_until_eof(pipefd[0])))
//				return (NULL);
			if (!(arg_tab = craft_arg(pipefd[0])))
				return (-1);
			dup2(pipefd[0], 0);
			ft_printtab(arg_tab);
//			if (execve("/usr/bin/wc", arg_tab, env) == -1)
//	           perror("execve");
//			read(pipefd[0], buffer, 99);
			fork_and_exec("/usr/bin/wc", arg_tab, pipefd, env);
			wait(&status); /* Oui, il faudrait vérifier la valeur de retour... */
			close(pipefd[1]);
		}

  		printf("My pid is: %d\n", getpid());
 		ft_printf("buffer: %s", buffer);
	}

  return 0;
}