/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:29:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 02:51:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_errors.h"
#include "internals.h"
#include "builtins.h"

static int	find_variable_by_name(const char *name, t_string_list *sl_env)
{
	size_t	index;
	size_t	size;

	index = 0;
	while (sl_env->items[index] != NULL)
	{
		size = ft_strlen(name);
		if (ft_strncmp(name, sl_env->items[index], size) == 0)
			return (index);
		index++;
	}
	return (NOT_FOUND);
}

static int	unset_variable_error(char *arg, t_string_list *copy)
{
	g_env = string_list_to_string_array(copy);
	string_list_delete(&copy);
	print_internal_error("unset", arg, ERROR_NOT_VALID_IDENTIFIER, TRUE);
	return (ERROR_NOT_VALID_IDENTIFIER);
}

int			unset(char **args)
{
	t_string_list	*copy;
	size_t			index;
	int				found;

	copy = NULL;
	string_list_create_from(&copy, g_env, ft_tablen(g_env));
	if (copy == NULL)
		return (ERR_MALLOC_FAILED);
	index = 1;
	while (args[index] != NULL)
	{
		if (!is_valid_variable(args[index]))
			return (unset_variable_error(args[index], copy));
		found = find_variable_by_name(args[index], copy);
		if (found != NOT_FOUND)
		{
			if (string_list_pop(copy, found) == ERR_MEM_ALLOC_FAILED)
				return (ERR_MALLOC_FAILED);
		}
		index++;
	}
	g_env = string_list_to_string_array(copy);
	string_list_delete(&copy);
	return (SUCCESS);
}
