/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:53:10 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 20:57:14 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_option(t_queue **head, const char *input, size_t index)
{
	const size_t previous = index;

	while (input[index] != '\0' && !is_sep(input[index]))
		index++;
	enqueue(head, (t_token){
		.type = OPTION,
		.value = ft_strndup(&input[previous], index - previous),
		.index = previous
	});
	return (index);
}
