/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:24:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/04 19:01:04 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <stddef.h>

typedef struct  s_spair
{
    char *key;
    char *value;
}               t_spair;

typedef struct {
	size_t begin;
	size_t end;
}		t_slice;

#endif