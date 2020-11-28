/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 07:54:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/28 07:55:28 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internals.h"
#include "internal_errors.h"

char	*make_variable(const char *key)
{
	size_t	key_size;
	char	*variable;

	key_size = ft_strlen(key);
	variable = malloc(sizeof(char) * (key_size + 1 + 1));
	if (variable == NULL)
		return (NULL);
	ft_strcpy(variable, key);
	variable[key_size] = '=';
	variable[key_size + 1] = '\0';
	return (variable);
}

int		export_key(char *key)
{
	t_string_list	*list;
	int				index;
	char			*variable;

	list = NULL;
	string_list_create_from(&list, g_env, string_arr_len(g_env));
	if (list == NULL)
		return (ERR_MALLOC_FAILED);
	if ((index = find_key(list, key)) != NOT_FOUND)
		return (FAILURE);
	variable = make_variable(key);
	if (variable == NULL)
	{
		string_list_delete(&list);
		return (ERR_MALLOC_FAILED);
	}
	if (string_list_append(list, variable) == ERR_MEM_ALLOC_FAILED)
	{
		string_list_delete(&list);
		return (ERR_MALLOC_FAILED);
	}
	free(variable);
	g_env = string_list_to_string_array(list);
	string_list_delete(&list);
	return (SUCCESS);
}
