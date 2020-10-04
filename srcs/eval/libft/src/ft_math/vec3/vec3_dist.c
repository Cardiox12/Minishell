/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:25:26 by bbellavi          #+#    #+#             */
/*   Updated: 2020/07/02 19:26:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	dist_vec3(t_vec3 a, t_vec3 b)
{
	const int dist = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);

	return (sqrt(dist));
}
