/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_key_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 07:55:41 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/28 07:55:52 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internals.h"
#include "internal_errors.h"

int	export_key_value(char *variable)
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
