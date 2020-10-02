/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:23:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/18 09:58:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec	vec2_to_vec(t_vec2 a)
{
	t_vec ret;

	ret.x = (int)a.x;
	ret.y = (int)a.y;
	return (ret);
}

t_vec3	vec2_to_vec3(t_vec2 a)
{
	t_vec3 ret;

	ret.x = (double)a.x;
	ret.y = (double)a.y;
	return (ret);
}