/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:49:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 02:32:51 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "lexer.h"
#include <stdio.h>

int	get_argument(t_queue **head, const char *input, size_t index)
{
	const size_t	previous = index;
	char			*value;
	int				prefixed;

	prefixed = FALSE;
	while (!is_sep(input[index]) && input[index] != '\0')
	{
		if (is_escaped(&input[index]))
			index++;
		index++;
	}
	value = ft_strndup(&input[previous], index - previous);
	value = str_expand(&value, ARGUMENT);
	if (ft_isquote(input[index]))
		prefixed = TRUE;
	enqueue(head, (t_token){
		.type = ARGUMENT,
		.value = value,
		.index = previous,
		.prefixed = prefixed
	});
	return (index);
}
