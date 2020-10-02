/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:26:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/18 10:06:44 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float	get_angle(t_vec a, t_vec b)
{
	const float dot = vec_dot(a, b);

	return (acos(dot / (vec_mag(a) * vec_mag(b))));
}
