/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_none.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 07:54:08 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/29 07:35:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internals.h"
#include "internal_errors.h"

void	swap_strings(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

char	**sorted(char **src)
{
	int		size;
	t_vec	indices;
	char	**copy;

	copy = NULL;
	ft_tab_copy(&copy, src);
	indices.y = 0;
	size = ft_tablen(copy);
	while (indices.y < size)
	{
		indices.x = 0;
		while (indices.x < size - indices.y - 1)
		{
			if (*copy[indices.x] > *copy[indices.x + 1])
				swap_strings(&copy[indices.x], &copy[indices.x + 1]);
			indices.x++;
		}
		indices.y++;
	}
	return (copy);
}

int		print_export(char **variables, size_t index)
{
	t_spair	items;
	char	*variable;

	variable = variables[index];
	if (ft_strchr(variable, SYM_EQUAL) == NULL)
	{
		ft_printf("declare -x %s\n", variable);
	}
	else
	{
		items = get_items(variable);
		if (items.first == NULL && items.second == NULL)
		{
			ft_freetab(&variables);
			return (ERR_MALLOC_FAILED);
		}
		ft_printf("declare -x %s=\"%s\"\n", items.first, items.second);
		free_spair(items);
	}
	return (SUCCESS);
}

int		export_none(void)
{
	size_t			index;
	char			**copy;

	index = 0;
	copy = sorted(g_env);
	while (copy[index] != NULL)
	{
		if (print_export(copy, index))
			return (ERR_MALLOC_FAILED);
		index++;
	}
	ft_freetab(&copy);
	return (SUCCESS);
}
