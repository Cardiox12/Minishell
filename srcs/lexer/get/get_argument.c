/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:49:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/03 23:42:20 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "lexer.h"

int	get_argument(t_queue **head, const char *input, size_t index)
{
	const size_t	previous = index;
	char			*value;

	while (!is_sep(input[index]) && input[index] != '\0')
		index++;
	value = ft_strndup(&input[previous], index - previous);
	value = expand(value, ARGUMENT);
	enqueue(head, (t_token){
		.type = ARGUMENT,
		.value = value,
		.index = previous
	});
	return (index);
}
