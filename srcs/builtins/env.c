/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:31:18 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/29 07:22:46 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	env(char **args)
{
	size_t index;

	(void)args;
	index = 0;
	while (g_env[index] != NULL)
	{
		if (ft_strchr(g_env[index], SYM_EQUAL) != NULL)
			ft_printf("%s\n", g_env[index]);
		index++;
	}
	return (0);
}
