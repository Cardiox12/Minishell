/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:19:56 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 11:45:46 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_sep(int c)
{
	return (ft_isspace(c) || c == SYM_PIPE || c == SYM_OPERATOR ||
	c == SYM_QUOTE || c == SYM_SIMPLE_QUOTE);
}

int	is_basic_sep(int c)
{
	return (ft_isspace(c) || c == SYM_PIPE || c == SYM_OPERATOR);
}
