/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:20:38 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 01:21:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*quote_extract(const char *input, size_t *index)
{
	const int	quote = input[*index];
	size_t		previous;
	char		*content;

	previous = *index;
	while (input[*index] == quote)
		(*index)++;
	if ((ft_isspace(input[*index]) || input[*index] == '\0')
	&& (*index - previous) % 2 == 0)
		return (ft_strdup(""));
	previous = *index;
	while (input[*index] != quote)
		(*index)++;
	content = ft_strndup(&input[previous], *index - previous);
	while (input[*index] == quote)
		(*index)++;
	return (content);
}
