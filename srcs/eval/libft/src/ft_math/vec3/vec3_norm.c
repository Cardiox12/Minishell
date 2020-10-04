/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:22:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/07/02 19:27:33 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec3	norm_vec3(t_vec3 a)
{
	const double	mag = sqrt((a.x * a.x) + (a.y * a.y));
	t_vec3			res;

	res.x = a.x / (float)mag;
	res.y = a.y / (float)mag;
	return (res);
}
