/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:22:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/26 02:29:57 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec2	norm_vec2(t_vec2 a)
{
	const double	mag = sqrt((a.x * a.x) + (a.y * a.y));
	t_vec2			res;

	res.x = a.x / (float)mag;
	res.y = a.y / (float)mag;
	return (res);
}
