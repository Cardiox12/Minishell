/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:50:25 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 00:23:29 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_fd(t_queue **head, const char *input, size_t index)
{
	const size_t previous = index;

	while (!is_sep(input[index]) && input[index] != '\0')
		index++;
	enqueue(head, (t_token){
		.type = FILE_DESCRIPTOR,
		.value = ft_strndup(&input[previous], index - previous),
		.index = previous,
		.prefixed = FALSE
	});
	return (index);
}
