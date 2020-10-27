#include "../../includes/eval.h"
extern int test_file;

# define BUF_SIZE 4

char	*read_until_eof(int fd)
{
	char	*total_data;
	char	buffer[BUF_SIZE + 1];
	int		ret;

//	ft_bzero(buffer, 512);
	ret = read(fd, buffer, BUF_SIZE);
	buffer[BUF_SIZE] = '\0';
	if (!(total_data = ft_strdup(buffer)))
		return (NULL);
//	ft_bzero(buffer, BUF_SIZE);
	while ((ret = read(fd, buffer, BUF_SIZE)) > 0)
	{
		buffer[ret] = '\0';

//		write(test_file, buffer, BUF_SIZE);
		if (!(total_data = ft_join_free_left(&total_data, buffer)))
			return (NULL);
//		ft_bzero(buffer, 512);	
	}
	return (total_data);
}