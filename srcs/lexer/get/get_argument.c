/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:49:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/22 23:53:31 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_argument(t_queue **head, const char *input, size_t index)
{
	const size_t previous = index;

	while (!is_sep(input[index]) && input[index] != '\0')
		index++;
	enqueue(head, (t_token){
		.type = ARGUMENT,
		.value = ft_strndup(&input[previous], index - previous),
		.index = previous
	});
	return (index);
}
