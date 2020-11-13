/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:47:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/13 14:49:07 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    interpret_free(t_interpret *interpret)
{
    queue_free(interpret->current);
    queue_delete(&interpret->tokens);
}