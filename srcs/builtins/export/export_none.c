/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_none.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 07:54:08 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/28 09:04:23 by bbellavi         ###   ########.fr       */
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
	size_t	size;
	size_t	index;
	char	**copy;

	copy = NULL;
	ft_tab_copy(&copy, src);
	index = 0;
	size = ft_tablen(copy);
	while (index < size - 1)
	{
		if (*copy[index] > *copy[index + 1])
		{
			swap_strings(&copy[index], &copy[index + 1]);
			index = 0;
		}
		index++;
	}
	return (copy);
}

int		export_none(void)
{
	t_spair			items;
	size_t			index;
	char			**copy;

	index = 0;
	copy = sorted(g_env);
	while (copy[index] != NULL)
	{
		items = get_items(copy[index]);
		if (items.first == NULL && items.second == NULL)
		{
			ft_freetab(&copy);
			return (ERR_MALLOC_FAILED);
		}
		ft_printf("declare -x %s=\"%s\"\n", items.first, items.second);
		free_spair(items);
		index++;
	}
	ft_freetab(&copy);
	return (SUCCESS);
}
