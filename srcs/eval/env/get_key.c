/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:32:35 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:46:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "eval.h"

char	*get_key(const char *variable)
{
	char	*key;
	char	*equal;

	equal = ft_strchr(variable, SYM_EQUAL);
	if (equal == NULL)
		key = ft_strdup(variable);
	else
		key = ft_strndup(variable, equal - variable);
	if (key == NULL)
		return (NULL);
	return (key);
}
