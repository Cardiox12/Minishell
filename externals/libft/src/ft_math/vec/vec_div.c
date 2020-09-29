/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:24:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/26 02:28:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec	div_vec(t_vec a, int scalar)
{
	t_vec ret;

	ret.x = a.x / scalar;
	ret.y = a.y / scalar;
	return (ret);
}
