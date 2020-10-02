/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:24:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/07/02 19:26:49 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec3	div_vec3(t_vec3 a, int scalar)
{
	t_vec3 ret;

	ret.x = a.x / scalar;
	ret.y = a.y / scalar;
	return (ret);
}
