/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:23:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/07/02 19:36:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec	vec3_to_vec(t_vec3 a)
{
	t_vec ret;

	ret.x = (int)a.x;
	ret.y = (int)a.y;
	return (ret);
}

t_vec2	vec3_to_vec2(t_vec3 a)
{
	t_vec2 ret;

	ret.x = (float)a.x;
	ret.y = (float)a.y;
	return (ret);
}
