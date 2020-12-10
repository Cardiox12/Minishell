/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:54:16 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 10:03:38 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "lexer.h"

int	get_env_variable(t_queue **head, const char *input, size_t index)
{
	const size_t	previous = index;
	char			*value;

	if (input[index + 1] == '?' || ft_isdigit(input[index + 1]))
	{
		index += 2;
		value = ft_strndup(&input[previous], index - previous);
	}
	else
	{
		while (input[index] != '\0' && !is_sep(input[index]))
			index++;
		value = ft_strndup(&input[previous], index - previous);
	}
	value = str_expand(&value, ENV_VARIABLE);
	enqueue(head, (t_token){
		.type = ENV_VARIABLE,
		.value = value,
		.index = previous,
		.prefixed = !is_sep(input[index])
	});
	return (index);
}
