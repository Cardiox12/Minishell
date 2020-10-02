/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 09:51:34 by tony              #+#    #+#             */
/*   Updated: 2020/09/30 04:20:01 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

#include <stddef.h>
#include <stdlib.h>

typedef struct 			s_Ref_List
{
	void 				*ref;
	struct 	s_Ref_List 	*next;
}						t_Ref_List;

typedef struct 	s_Garbage 
{
	int			length;
	t_Ref_List	*refs;
}				t_Garbage;

extern t_Garbage g_garbage;

void		*ft_realloc(void *p, size_t new_size, size_t old_size);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_itoa(int n);

t_Ref_List	*garbage_add_ref(void *p);
void 		garbage_free(void *p);
void		garbage_free_all(void);
void		garbage_update_ref(void *pold, void *pnew);
t_Ref_List	*garbage_find_ref(void *p);
void		*malloc_wrapper(size_t size);
void		*realloc_wrapper(void *p, size_t new_size, size_t old_size);

#endif