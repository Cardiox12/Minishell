/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_neg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:21:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/26 02:29:14 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec	neg_vec(t_vec a)
{
	t_vec ret;

	ret.x = -a.x;
	ret.y = -a.y;
	return (ret);
}
