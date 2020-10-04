/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:23:03 by bbellavi          #+#    #+#             */
/*   Updated: 2020/07/02 19:26:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec3	mult_vec3(t_vec3 a, float scalar)
{
	t_vec3 ret;

	ret.x = a.x * scalar;
	ret.y = a.y * scalar;
	return (ret);
}
