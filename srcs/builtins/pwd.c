/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:16:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:18:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	pwd(char **args)
{
	char path[PATH_MAX];

	(void)args;
	if (getcwd(path, PATH_MAX) == NULL)
		return (errno);
	ft_printf("%s\n", path);
	return (SUCCESS);
}
