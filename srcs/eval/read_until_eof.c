#include "../../includes/eval.h"
extern int test_file;

# define BUF_SIZE 100

char	*read_until_eof(int fd)
{
	char	*total_data;
	char	buffer[BUF_SIZE + 1];
	int		ret;

	ret = read(fd, buffer, BUF_SIZE);
	buffer[ret] = '\0';
	if (!(total_data = ft_strdup(buffer)))
		return (NULL);
	while ((ret = read(fd, buffer, BUF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!(total_data = ft_join_free_left(&total_data, buffer)))
			return (NULL);
	}
	return (total_data);
}