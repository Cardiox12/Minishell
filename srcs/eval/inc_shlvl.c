/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 07:48:57 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/29 08:51:49 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "builtins.h"
#include "eval.h"
#include "types.h"

static char	*make_key_val(t_spair pair)
{
	size_t	size;
	char	*variable;

	size = ft_strlen(pair.first) + ft_strlen(pair.second) + 1 + 1;
	variable = ft_strnew(size);
	if (variable == NULL)
		return (NULL);
	ft_strlcat(variable, pair.first, size + 1);
	ft_strlcat(variable, "=", size + 1);
	ft_strlcat(variable, pair.second, size + 1);
	return (variable);
}

static void	inc_shlvl_(const char *variable)
{
	t_spair	items;
	t_spair	exp_items;
	char	*final;
	int		shlvl;

	items = get_items(variable);
	if (items.first == NULL && items.second == NULL)
		return ;
	shlvl = ft_atoi(items.second) + 1;
	exp_items = (t_spair){ft_strdup(items.first), ft_itoa(shlvl)};
	if (exp_items.second == NULL)
	{
		free_spair(items);
		return ;
	}
	final = make_key_val(exp_items);
	if (variable == NULL)
	{
		free_spair(items);
		free(final);
		return ;
	}
	export((t_string[3]){BUILTINS_EXPORT, final, NULL});
	free_spair(exp_items);
	free_spair(items);
	free(final);
}

void		inc_shlvl(void)
{
	char *variable;

	variable = find_variable(SHLVL_NAME);
	if (variable != NULL)
	{
		inc_shlvl_(variable);
	}
}