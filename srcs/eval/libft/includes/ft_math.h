/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 04:14:21 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/18 10:05:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

#include <math.h>

typedef struct	s_vec
{
	int x;
	int y;
}				t_vec;

typedef struct	s_vec2
{
	float x;
	float y;
}				t_vec2;

typedef struct	s_vec3
{
	double x;
	double y;
}				t_vec3;

# define CLOCKWISE 1
# define ANTI_CLOCKWISE 0

t_vec2	rotate_vec2(t_vec2 u, double theta, char clockwise);
t_vec3	rotate_vec3(t_vec3 u, double theta, char clockwise);
t_vec2	norm_vec2(t_vec2 a);
t_vec	norm_vec(t_vec a);
t_vec	neg_vec(t_vec a);
t_vec2	neg_vec2(t_vec2 a);
t_vec	add_vec(t_vec a, t_vec b);
t_vec2	add_vec2(t_vec2 a, t_vec2 b);
t_vec	mult_vec(t_vec a, float scalar);
t_vec2	mult_vec2(t_vec2 a, float scalar);
t_vec2	div_vec2(t_vec2 a, int scalar);
t_vec	div_vec(t_vec a, int scalar);
double	dist_vec(t_vec a, t_vec b);
double	dist_vec2(t_vec2 a, t_vec2 b);
float	vec_dot(t_vec a, t_vec b);
float	vec2_dot(t_vec2 a, t_vec2 b);
float	vec3_dot(t_vec3 a, t_vec3 b);
float	get_angle(t_vec a, t_vec b);
float	get_angle2(t_vec2 a, t_vec2 b);
float	vec_mag(t_vec a);
float	vec2_mag(t_vec2 a);
float	vec3_mag(t_vec3 a);

t_vec	vec2_to_vec(t_vec2 a);
t_vec	vec3_to_vec(t_vec3 a);
t_vec2	vec_to_vec2(t_vec a);
t_vec2	vec2_to_vec2(t_vec2 a);
t_vec2	vec3_to_vec2(t_vec3 a);
t_vec3	vec_to_vec3(t_vec a);
t_vec3	vec2_to_vec3(t_vec2 a);
t_vec3	vec3_to_vec3(t_vec3 a);

#endif