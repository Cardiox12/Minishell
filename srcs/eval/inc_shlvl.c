/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 07:48:57 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 13:32:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "builtins.h"
#include "eval.h"
#include "types.h"

typedef char* t_string;

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

static void	export_and_free(char *variable, t_spair exp, t_spair items)
{
	export((t_string[3]){BUILTINS_EXPORT, variable, NULL});
	free_spair(exp);
	free_spair(items);
	free(variable);
}

static int	get_shlvl(const char *variable)
{
	int shlvl;

	shlvl = ft_atoi(variable);
	ft_printf("shlvl : %s\n", variable);
	ft_printf("shlvl : %i\n", shlvl);
	if (shlvl < 0)
		shlvl = 0;
	else
		shlvl++;
	return (shlvl);
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
	shlvl = get_shlvl(items.second);
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
	export_and_free(final, exp_items, items);
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
