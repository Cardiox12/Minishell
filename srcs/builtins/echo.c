/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:11:29 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:33:49 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"
#include "builtins.h"

static char	*strconcat(char *dst, char *src)
{
	char	*prev;

	prev = dst;
	dst = ft_strjoin(dst, src);
	free(prev);
	if (dst == NULL)
		return (NULL);
	return (dst);
}

static char	*strcjoin(char **strings, char *charset)
{
	size_t	index;
	char	*string;

	index = 0;
	if ((string = ft_strdup("")) == NULL)
		return (NULL);
	while (strings[index] != NULL)
	{
		string = strconcat(string, strings[index]);
		if (string == NULL)
			return (NULL);
		if (strings[index + 1] != NULL)
		{
			string = strconcat(string, charset);
			if (string == NULL)
				return (NULL);
		}
		index++;
	}
	return (string);
}

static int	is_endl(const char *argument)
{
	if (argument != NULL)
	{
		if (ft_strncmp(argument, RAW_ARGUMENT, 2) == 0)
			return (TRUE);
	}
	return (FALSE);
}

int			echo(char **args)
{
	size_t	index;
	int		endl;
	char	*string;

	index = 1;
	endl = TRUE;
	if (is_endl(args[index]))
	{
		endl = FALSE;
		index++;
	}
	string = strcjoin(&args[index], " ");
	if (string == NULL)
		return (ERR_MALLOC_FAILED);
	if (endl)
		ft_putendl_fd(string, 1);
	else
		ft_putstr_fd(string, 1);
	free(string);
	return (SUCCESS);
}
