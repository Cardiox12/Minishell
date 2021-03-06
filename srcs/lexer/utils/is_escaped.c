/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_escaped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:12:32 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 02:32:15 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "lexer.h"

int	is_escaped(const char *s)
{
	if (*s == '\0')
		return (FALSE);
	return (s[0] == SYM_ESC && ft_isprint(s[1]));
}

int	is_escaped_by(const char *s, char *charset)
{
	if (*s == '\0')
		return (FALSE);
	return (s[0] == SYM_ESC && ft_strchr(charset, s[1]) != NULL);
}
