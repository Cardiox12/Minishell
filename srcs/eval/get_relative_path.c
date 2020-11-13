/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_relative_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:56:29 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/09 15:56:30 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "eval.h"

char	*free_str_ret_null(char **str)
{
	ft_strdel(str);
	return (NULL);
}

char	*get_relative_path(char *value)
{
	char	cwd[PATH_MAX];
	char	*cwd_slashed;
	char	*full_relative_path;

	getcwd(cwd, PATH_MAX);
	if (!(cwd_slashed = ft_strjoin(cwd, "/")))
		return (NULL);
	if (value[0] == '.' && value[1] == '/')
	{
		if (!(full_relative_path = ft_str_replace(value, ".", cwd)))
			return (free_str_ret_null(&cwd_slashed));
	}
	else
	{
		if (!(full_relative_path = ft_strjoin(cwd_slashed, value)))
			return (free_str_ret_null(&cwd_slashed));
	}
	ft_strdel(&cwd_slashed);
	return (full_relative_path);
}
