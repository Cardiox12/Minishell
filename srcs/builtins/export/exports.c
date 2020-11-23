/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:36:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 11:30:27 by bbellavi         ###   ########.fr       */
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

int		export_key_value(char *variable)
{
	t_string_list	*list;
	int				index;
	char			*key;

	list = NULL;
	key = get_key(variable);
	string_list_create_from(&list, g_env, string_arr_len(g_env));
	if (list == NULL)
		return (ERR_MALLOC_FAILED);
	if ((index = find_key(list, key)) != NOT_FOUND)
	{
		free(key);
		free(list->items[index]);
		if ((list->items[index] = ft_strdup(variable)) == NULL)
			return (ERR_MALLOC_FAILED);
	}
	else
	{
		free(key);
		if (string_list_append(list, variable) == ERR_MEM_ALLOC_FAILED)
			return (ERR_MALLOC_FAILED);
	}
	g_env = string_list_to_string_array(list);
	string_list_delete(&list);
	return (SUCCESS);
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

int		export_none(void)
{
	t_spair	items;
	size_t	index;

	index = 0;
	while (g_env[index] != NULL)
	{
		items = get_items(g_env[index]);
		if (items.key == NULL && items.value == NULL)
			return (ERR_MALLOC_FAILED);
		ft_printf("declare -x %s=\"%s\"\n", items.key, items.value);
		free_spair(items);
		index++;
	}
	return (SUCCESS);
}
