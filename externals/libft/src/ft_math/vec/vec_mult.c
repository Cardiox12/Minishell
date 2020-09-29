/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:23:03 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/26 02:29:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec	mult_vec(t_vec a, float scalar)
{
	t_vec ret;

	ret.x = a.x * scalar;
	ret.y = a.y * scalar;
	return (ret);
}
