/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 01:10:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/22 23:35:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_ctypes.h"
#include "builtins.h"
#include "eval.h"

static int	is_var_charset(int c)
{
	return (ft_isalnum(c) || c == '_' || c == '?');
}

static char	*extract_and_replace(char *src, const char *value, t_slice slice)
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

static char	*replace(char **src, t_slice slice)
{
	char	*previous;
	t_spair	items;

	items.key = ft_substr(*src, slice.begin + 1, slice.end - (slice.begin + 1));
	if (items.key == NULL)
		return (NULL);
	if (ft_strncmp(items.key, EXIT_CODE_SYM, 1) == 0)
		items.value = ft_itoa(g_exitstatus);
	else
		items.value = get_value(find_variable(items.key));
	if (items.value == NULL)
		items.value = ft_strdup("");
	previous = *src;
	*src = extract_and_replace(*src, items.value, slice);
	free(previous);
	free_spair(items);
	return (*src);
}

char		*expand(const char *src)
{
	char	*new;
	t_slice	slice;

	slice.begin = 0;
	if ((new = ft_strdup(src)) == NULL)
		return (NULL);
	while (new[slice.begin] != '\0')
	{
		if (is_escaped_by(&new[slice.begin], ESC_IMPROVED_CHARSET))
		{
			removal(&new, slice);
			slice.begin++;
		}
		else if (new[slice.begin] == SYM_ENV_VAR &&
		is_var_charset(new[slice.begin + 1]))
		{
			slice.end = slice.begin + 1;
			while (is_var_charset(new[slice.end]) && new[slice.end] != '\0')
				slice.end++;
			replace(&new, slice);
			slice.begin = 0;
		}
		else
			slice.begin++;
	}
	return (new);
}
