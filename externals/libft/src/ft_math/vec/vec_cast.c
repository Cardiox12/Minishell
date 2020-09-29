/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:23:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/07/02 19:36:16 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec2	vec_to_vec2(t_vec a)
{
	t_vec2 ret;

	ret.x = (float)a.x;
	ret.y = (float)a.y;
	return (ret);
}

t_vec3	vec_to_vec3(t_vec a)
{
	t_vec3 ret;

	ret.x = (double)a.x;
	ret.y = (double)a.y;
	return (ret);
}