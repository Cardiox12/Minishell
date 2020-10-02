#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "libft/ft_libft.h"

int		cd(char *path)
{
	int 	ret;

	ret = chdir(path);
	if (ret == -1)
		ft_printf("cd: %s: %s\n", strerror(errno), path);
	return (ret);
}

/*int		main(int ac, char **av)
{
	(void)ac;
	char	*pwd;

	cd(av[1]);
	pwd = getcwd(NULL, 1);
	printf("%s\n", pwd);
}*/
