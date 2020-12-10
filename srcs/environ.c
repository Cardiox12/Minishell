/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 07:11:01 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 01:40:29 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

typedef char*	t_string;

void	export_basic_environ(void)
{
	char	cwd[PATH_MAX + 1];
	size_t	index;

	index = 0;
	while (index < BASIC_ENVIRON_SIZE)
	{
		export((t_string[3]){
			BUILTINS_EXPORT,
			(char*)g_basic_environ[index],
			NULL
		});
		index++;
	}
	if (getcwd(cwd, PATH_MAX) != NULL)
		export((t_string[5]){BUILTINS_EXPORT, "PWD", "=", cwd, NULL});
}
