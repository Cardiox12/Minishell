/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:11:56 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 03:12:04 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_quote_closed(const char *s, char quote)
{
	int index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == quote)
			return (TRUE);
		if (is_escaped_by(&s[index], ESC_CHARSET))
			index++;
		index++;
	}
	g_quote_parity_error = FAILURE;
	return (FALSE);
}
