/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:32:42 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/28 00:36:12 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "eval.h"

char	*get_home(void)
{
	char *variable;
	char *home;

	variable = ft_strdup(find_variable("HOME"));
	home = get_value(variable);
	free(variable);
	return (home);
}
