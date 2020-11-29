/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:24:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/29 08:34:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <stdlib.h>
# include <stddef.h>

typedef char*	t_string;
typedef struct	s_spair
{
	char		*first;
	char		*second;
}				t_spair;

typedef struct	s_slice
{
	size_t		begin;
	size_t		end;
}				t_slice;

void			free_spair(t_spair pair);

#endif
