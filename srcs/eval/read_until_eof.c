#include "../../includes/eval.h"

char	*read_until_eof(int fd)
{
	char	*total_data;
	char	buffer[512];

	ft_bzero(buffer, 512);
	read(fd, buffer, 511);
	buffer[511] = '\0';
	if (!(total_data = ft_strdup(buffer)))
		return (NULL);
	ft_bzero(buffer, 512);
	while (read(fd, buffer, 511) > 0)
	{
		buffer[511] = '\0';
		if (!(total_data = ft_join_free_left(&total_data, buffer)))
			return (NULL);
		ft_bzero(buffer, 512);	
	}
	return (total_data);
}