/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:30:40 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/25 18:22:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internal_errors.h"

char			*make_key_value_variable(t_spair pair)
{
	size_t	size;
	char	*var;

	size = ft_strlen(pair.first) + ft_strlen(pair.second);
	var = ft_strnew(size);
	if (var == NULL)
		return (NULL);
	ft_strlcat(var, pair.first, size + 1);
	ft_strlcat(var, pair.second, size + 1);
	return (var);
}

char			*make_kv_var_equal(t_spair pair)
{
	size_t	size;
	char	*var;

	size = ft_strlen(pair.first) + ft_strlen(pair.second) + 1;
	var = ft_strnew(size);
	if (var == NULL)
		return (NULL);
	ft_strlcat(var, pair.first, size + 1);
	ft_strlcat(var, "=", size + 1);
	ft_strlcat(var, pair.second, size + 1);
	return (var);
}

int				parse_by_one(char **args)
{
	char *var;

	var = args[1];
	if (ft_isdigit(*var))
	{
		print_internal_error("export", var, ERROR_NOT_VALID_IDENTIFIER,
		TRUE);
		return (ERROR_NOT_VALID_IDENTIFIER);
	}
	if (ft_strchr(var, SYM_EQUAL) != NULL)
		export_key_value(var);
	else
		export_none();
	return (SUCCESS);
}

int				parse_by_two(char **args)
{
	t_spair	pair;
	char	*var;

	pair = (t_spair){args[1], args[2]};
	if (ft_isdigit(*pair.first))
	{
		print_internal_error("export", pair.first, ERROR_NOT_VALID_IDENTIFIER,
		TRUE);
		return (ERROR_NOT_VALID_IDENTIFIER);
	}
	if (ft_strchr(pair.first, SYM_EQUAL) != NULL ||
	ft_strchr(pair.second, SYM_EQUAL) != NULL)
	{
		var = make_key_value_variable(pair);
		if (var == NULL)
			return (ERR_MEM_ALLOC_FAILED);
		export_key_value(var);
		free(var);
	}
	else
	{
		export_key(pair.first);
		export_key(pair.second);
	}
	return (SUCCESS);
}

int				parse_by_three(char **args)
{
	t_spair	pair;
	char	*var;

	pair = (t_spair){args[1], args[3]};
	if (ft_isdigit(*pair.first))
	{
		print_internal_error("export", pair.first, ERROR_NOT_VALID_IDENTIFIER,
		TRUE);
		return (ERROR_NOT_VALID_IDENTIFIER);
	}
	if (ft_strncmp(args[2], "=", 1) == 0)
	{
		var = make_kv_var_equal(pair);
		export_key_value(var);
		free(var);
	}
	return (SUCCESS);
}
