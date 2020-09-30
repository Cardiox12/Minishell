/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:58:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/13 12:19:44 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_space(char c)
{
	return ((c == '\n' || c == '\t' || c == '\v' ||
				c == '\f' || c == '\r' || c == ' ') ? 1 : 0);
}

int			ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (*str != '\0' && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '+') ? sign : -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}
