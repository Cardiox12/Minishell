/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:22:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/26 02:29:46 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec	norm_vec(t_vec a)
{
	const double	mag = sqrt((a.x * a.x) + (a.y * a.y));
	t_vec			res;

	res.x = a.x / mag;
	res.y = a.y / mag;
	return (res);
}
