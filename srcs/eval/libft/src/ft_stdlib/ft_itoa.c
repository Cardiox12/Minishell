/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:50:47 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:50 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

static size_t	ft_get_number_len(int nb)
{
	size_t counter;

	counter = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (10);
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

char			*ft_itoa(int n)
{
	size_t	number_size;
	size_t	end;
	char	*number;

	number_size = (n > 0) ? ft_get_number_len(n) : ft_get_number_len(n) + 1;
	if ((number = malloc(sizeof(char) * (number_size + 1))) == NULL)
		return (NULL);
	number[number_size] = '\0';
	end = 0;
	if (n == -2147483648)
		return (ft_memcpy(number, "-2147483648", 12));
	if (n < 0)
	{
		n = -n;
		number[0] = '-';
		end = 1;
	}
	while (number_size > end)
	{
		number[--number_size] = ('0' + n % 10);
		n = n / 10;
	}
	return (number);
}
