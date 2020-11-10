/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 04:11:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	locate(char *haystack, char needle)
{
	int index;

	index = 0;
	while (haystack[index])
	{
		if (haystack[index] == needle)
			return (index);
		index++;
	}
	return (-1);
}

static char	*append(char **dst, const char *src)
{
	char *old_ptr;

	if (*dst == NULL)
		*dst = ft_strndup(src, ft_strlen(src));
	else
	{
		old_ptr = *dst;
		*dst = ft_strjoin(*dst, src);
		if (*dst == NULL)
			return (NULL);
		free(old_ptr);
	}
	return (*dst);
}

static char	*resize(char **dst, size_t start)
{
	char *old_ptr;

	if (*dst)
	{
		old_ptr = *dst;
		if ((*dst)[start] != '\0' && (*dst)[start] == NEWLINE)
			start++;
		*dst = ft_strndup(&(*dst)[start], ft_strlen(&(*dst)[start]));
		if (*dst == NULL)
			return (NULL);
		free(old_ptr);
	}
	return (*dst);
}

static int	get_line(char *buffer, char **dynamic, char **line)
{
	int		newline_pos;

	if (append(dynamic, buffer) == NULL)
		return (ERROR);
	if ((newline_pos = locate(buffer, NEWLINE)) != NOT_FOUND)
		buffer[0] = '\0';
	if ((newline_pos = locate(*dynamic, NEWLINE)) != NOT_FOUND)
	{
		*line = ft_strndup(*dynamic, newline_pos);
		if (resize(dynamic, newline_pos) == NULL || *line == NULL)
			return (ERROR);
		return (SUCCESS);
	}
	return (END_OF_FILE);
}

int			set_nl_watch(char *dynamic, int *nl_watch, int bytes)
{
	if (dynamic && ft_strlen(dynamic) != 0 && locate(dynamic, '\n') == NOT_FOUND)
		*nl_watch = 0;
	else
		*nl_watch = 1;
	if (bytes == 0 && *nl_watch == 1)
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*dynamic = NULL;
	int				bytes;
	int				key_code;
	int				nl_watch;

	if ((bytes = read(fd, buffer, 0)) == ERROR || fd == ERROR || line == NULL)
		return (ERROR);
	nl_watch = 0;
	while (((bytes = read(fd, buffer, BUFFER_SIZE)) > 0) || nl_watch == 0)
	{
		nl_watch = 1;
		buffer[bytes] = '\0';
		if ((key_code = get_line(buffer, &dynamic, line)) == ERROR
				|| key_code == SUCCESS)
			return (key_code);
		if (set_nl_watch(dynamic, &nl_watch, bytes) == -1)
			break;
		
	}
	buffer[bytes] = '\0';
	if ((key_code = get_line(buffer, &dynamic, line)) == SUCCESS
			|| key_code == ERROR)
		return (key_code);
	if ((*line = ft_strndup(dynamic, ft_strlen(dynamic))) == NULL)
		return (ERROR);
	free(dynamic);
	dynamic = NULL;
	return (END_OF_FILE);
}
