/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 08:00:54 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/07 00:41:39 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_objects.h"
#include "ft_strings.h"

static void	swap__(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	bubble_sort__(t_string_list *list)
{
	t_vec	i;
	int		is_sorted;

	i = (t_vec){0, list->length - 1};
	while (i.y > 0)
	{
		is_sorted = TRUE;
		while (i.x < i.y - 1)
		{
			if (list->items[i.x][0] > list->items[i.x + 1][0])
			{
				swap__(&list->items[i.x + 1], &list->items[i.x]);
				is_sorted = FALSE;
			}
			i.x++;
		}
		if (is_sorted)
			break ;
		i.y--;
	}
}

void		string_list_sort(t_string_list *list)
{
	if (list->length > 1)
	{
		bubble_sort__(list);
	}
}
