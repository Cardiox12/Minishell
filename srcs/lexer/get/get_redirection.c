/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:50:56 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 20:51:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int get_redirection(t_queue **head, const char *input, size_t index)
{
	const size_t previous = index;

	if (input[index] == SYM_R_REDIR && input[index + 1] == SYM_R_REDIR)
		index += 2;
	else if (input[index] == SYM_R_REDIR || input[index] == SYM_L_REDIR)
		index++;
	enqueue(head, (t_token){
		.type = REDIRECTION,
		.value = ft_strndup(&input[previous], index - previous),
		.index = index
	});
	return (index);
}
