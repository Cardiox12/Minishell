/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:24:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/13 20:12:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <stdlib.h>
# include <stddef.h>

typedef char* string;
typedef struct  s_spair
{
    char *key;
    char *value;
}               t_spair;

typedef struct {
	size_t begin;
	size_t end;
}		t_slice;

void    free_spair(t_spair pair);

#endif