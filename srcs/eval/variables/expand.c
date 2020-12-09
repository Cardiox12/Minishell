/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 01:10:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 02:34:52 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "builtins.h"
#include "expand.h"
#include "eval.h"

static char	*tilde_expand(char **src)
{
	char *home;

	if (ft_strncmp(*src, TILDE_SLASH, 2) == 0 || ft_strcmp(*src, TILDE) == 0)
	{
		home = get_home();
		if (home == NULL)
			return (NULL);
		str_replace(src, TILDE, home);
		free(home);
	}
	return (*src);
}

char		*basic_expand(char **src, char *charset)
{
	char	*new;
	t_slice	slice;

	slice.begin = 0;
	new = *src;
	while (new[slice.begin] != '\0')
	{
		if (is_escaped_by(&new[slice.begin], charset))
		{
			removal(&new, slice);
			if (new[slice.begin] != '\0')
				slice.begin++;
		}
		else if (is_bash_var(new, slice))
		{
			slice.end = slice.begin + 1;
			while (is_var_charset(new[slice.end]) && new[slice.end] != '\0')
				slice.end++;
			variable_replace(&new, slice);
		}
		else
			slice.begin++;
	}
	*src = new;
	return (new);
}

char		*medium_expand(char **src)
{
	char	*new;
	t_slice	slice;

	slice.begin = 0;
	new = *src;
	while (new[slice.begin] != '\0')
	{
		if (is_escaped(&new[slice.begin]))
		{
			removal(&new, slice);
			if (new[slice.begin] != '\0')
				slice.begin++;
		}
		else if (is_bash_var(new, slice))
		{
			slice.end = slice.begin + 1;
			while (is_var_charset(new[slice.end]) && new[slice.end] != '\0')
				slice.end++;
			variable_replace(&new, slice);
		}
		else
			slice.begin++;
	}
	*src = new;
	return (new);
}

char		*expand(const char *src, int tok_type)
{
	char *new;

	if ((new = ft_strdup(src)) == NULL)
		return (NULL);
	if (tok_type == ARGUMENT)
	{
		tilde_expand(&new);
		medium_expand(&new);
	}
	else
	{
		basic_expand(&new, ESC_IMPROVED_CHARSET);
	}
	return (new);
}

char		*str_expand(char **src, int tok_type)
{
	char *old;

	old = *src;
	*src = expand(*src, tok_type);
	free(old);
	return (*src);
}
