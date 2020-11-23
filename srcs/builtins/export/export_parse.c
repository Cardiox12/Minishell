/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:30:40 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 11:29:58 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internal_errors.h"

char			*make_key_value_variable(t_spair pair)
{
	size_t	size;
	char	*var;

	size = ft_strlen(pair.key) + ft_strlen(pair.value);
	var = ft_strnew(size);
	if (var == NULL)
		return (NULL);
	ft_strlcat(var, pair.key, size + 1);
	ft_strlcat(var, pair.value, size + 1);
	return (var);
}

char			*make_kv_var_equal(t_spair pair)
{
	size_t	size;
	char	*var;

	size = ft_strlen(pair.key) + ft_strlen(pair.value) + 1;
	var = ft_strnew(size);
	if (var == NULL)
		return (NULL);
	ft_strlcat(var, pair.key, size + 1);
	ft_strlcat(var, "=", size + 1);
	ft_strlcat(var, pair.value, size + 1);
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
	t_spair pair;

	pair = (t_spair){args[1], args[2]};
	if (ft_isdigit(*pair.key))
	{
		print_internal_error("export", pair.key, ERROR_NOT_VALID_IDENTIFIER,
		TRUE);
		return (ERROR_NOT_VALID_IDENTIFIER);
	}
	if (ft_strchr(pair.key, SYM_EQUAL) != NULL ||
	ft_strchr(pair.value, SYM_EQUAL) != NULL)
		export_key_value(make_key_value_variable(pair));
	else
	{
		export_key(pair.key);
		export_key(pair.value);
	}
	return (SUCCESS);
}

int				parse_by_three(char **args)
{
	t_spair	pair;
	char	*var;

	pair = (t_spair){args[1], args[3]};
	if (ft_isdigit(*pair.key))
	{
		print_internal_error("export", pair.key, ERROR_NOT_VALID_IDENTIFIER,
		TRUE);
		return (ERROR_NOT_VALID_IDENTIFIER);
	}
	if (ft_strncmp(args[2], "=", 1) == 0)
	{
		var = make_kv_var_equal(pair);
		export_key_value(var);
	}
	return (SUCCESS);
}
