/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:10:08 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/28 00:44:42 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "ft_ctypes.h"
#include "ft_stdlib.h"
#include "builtins.h"
#include "eval.h"

int		is_var_charset(int c)
{
	return (ft_isalnum(c) || c == '_' || c == '?');
}

int		is_bash_var(const char *s, t_slice slice)
{
	return (s[slice.begin] == SYM_ENV_VAR &&
	is_var_charset(s[slice.begin + 1]));
}

char	*extract_and_replace(char *src, const char *value, t_slice slice)
{
	const size_t	slength = ft_strlen(src);
	const size_t	vlength = ft_strlen(value);
	size_t			total;
	char			*new;

	total = slice.begin + vlength + (slength - slice.end);
	new = malloc(sizeof(char) * (total + 1));
	if (new == NULL)
		return (NULL);
	ft_bzero(new, total);
	ft_strncpy(new, src, slice.begin);
	ft_strcpy(&new[slice.begin], value);
	ft_strcpy(&new[slice.begin + vlength], &src[slice.end]);
	return (new);
}

char	*variable_replace(char **src, t_slice slice)
{
	char	*previous;
	t_spair	items;

	items.first = ft_substr(*src, slice.begin + 1,
	slice.end - (slice.begin + 1));
	if (items.first == NULL)
		return (NULL);
	if (ft_strncmp(items.first, EXIT_CODE_SYM, 1) == 0)
		items.second = ft_itoa(g_exitstatus);
	else
		items.second = get_value(find_variable(items.first));
	if (items.second == NULL)
		items.second = ft_strdup("");
	previous = *src;
	*src = extract_and_replace(*src, items.second, slice);
	free(previous);
	free_spair(items);
	return (*src);
}
