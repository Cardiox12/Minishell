/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_escaped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:12:32 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 03:14:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "lexer.h"

int	is_escaped_by(const char *s, char *charset)
{
	if (*s == '\0')
		return (FALSE);
	return (s[0] == SYM_ESC && ft_strchr(charset, s[1]));
}
