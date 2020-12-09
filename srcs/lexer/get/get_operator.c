/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:51:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/09 00:22:28 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_operator(t_queue **head, size_t index)
{
	enqueue(head, (t_token){
		.type = OPERATOR,
		.value = ft_strdup(";"),
		.index = index,
		.prefixed = FALSE
	});
	return (++index);
}
