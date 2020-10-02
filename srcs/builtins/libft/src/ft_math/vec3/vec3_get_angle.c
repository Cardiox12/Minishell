/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_get_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:26:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/18 10:05:33 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float	get_angle3(t_vec3 a, t_vec3 b)
{
	const float dot = vec3_dot(a, b);

	return (acos(dot / (vec3_mag(a) * vec3_mag(b))));
}
