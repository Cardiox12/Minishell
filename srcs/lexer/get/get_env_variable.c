/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:54:16 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/03 23:46:11 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "lexer.h"

int	get_env_variable(t_queue **head, const char *input, size_t index)
{
	const size_t	previous = index;
	char			*value;

	while (input[index] != '\0' && !is_sep(input[index]))
		index++;
	value = ft_strndup(&input[previous], index - previous);
	value = expand(value, ENV_VARIABLE);
	enqueue(head, (t_token){
		.type = ENV_VARIABLE,
		.value = value,
		.index = previous
	});
	return (index);
}
