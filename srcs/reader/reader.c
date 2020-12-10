/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 04:28:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 10:08:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"
#include <fcntl.h>

int		quote_finder(char *str)
{
	if (ft_strchr(str, '\'') == NULL && ft_strchr(str, '\"') == NULL)
		return (0);
	else
		return (1);
}

int		quotes_util(char **next_command, char **str, int *len)
{
	ft_printf("> ");
	get_next_line(0, next_command);
	*str = ft_join_free_left(str, "\n");
	*str = ft_join_free_left(str, *next_command);
	*len = ft_strlen(*str);
	return (0);
}

char	*handle_quotes(char **str)
{
	char	*next_command;
	int		quote_char;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(*str);
	while (i < len)
	{
		if ((*str)[i] == '\"' || (*str)[i] == '\'')
		{
			quote_char = (*str)[i];
			i++;
			while ((*str)[i] != quote_char)
			{
				i++;
				if (i >= len)
					quotes_util(&next_command, str, &len);
			}
		}
		i++;
	}
	return (*str);
}

char	*back_slash_handle(char **command)
{
	char	*next_command;
	int		len;

	len = ft_strlen(*command);
	while ((*command)[len - 1] == '\\')
	{
		(*command)[len - 1] = '\0';
		ft_printf("> ");
		get_next_line(0, &next_command);
		*command = ft_join_free_left(command, next_command);
		if (quote_finder(*command) == 1)
			*command = handle_quotes(command);
		len = ft_strlen(*command);
	}
	return (*command);
}

int		reader(char **command)
{
	char	cwd[PATH_MAX];
	int		gnl_return;

	*command = NULL;
	ft_bzero(cwd, PATH_MAX);
	getcwd(cwd, PATH_MAX);
	ft_printf("minishell@%s: ", cwd);
	if ((gnl_return = get_next_line(0, command)) == -1)
		return (-1);
	if (gnl_return == 0)
	{
		write(1, "exit\n", 5);
		ft_freetab(&g_env);
		exit(EXIT_SUCCESS);
	}
	if (*command == NULL)
		return (0);
	return (1);
}
