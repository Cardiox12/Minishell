/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issymbol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:26:53 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 12:16:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

int	ft_issymbol(char c)
{
	return (ft_strchr(CONVERSIONS, c) || ft_strchr(FLAGS, c) || ft_isdigit(c));
}
