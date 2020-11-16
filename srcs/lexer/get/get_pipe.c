/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:52:27 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 20:52:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_pipe(t_queue **head, size_t index)
{
	enqueue(head, (t_token){
		.type = PIPE,
		.value = ft_strdup("|"),
		.index = index
	});
	return (++index);
}
