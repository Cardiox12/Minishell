/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 09:51:34 by tony              #+#    #+#             */
/*   Updated: 2020/11/16 03:02:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>
# include <stdlib.h>

typedef struct			s_ref_list
{
	void				*ref;
	struct s_ref_list	*next;
}						t_ref_list;

typedef struct			s_garbage
{
	int					length;
	t_ref_list			*refs;
}						t_garbage;

extern t_garbage		g_garbage;

void					*ft_realloc(void *p, size_t new_size, size_t old_size);
int						ft_atoi(const char *str);
void					*ft_calloc(size_t count, size_t size);
char					*ft_itoa(int n);

t_ref_list				*garbage_add_ref(void *p);
void					garbage_free(void *p);
void					garbage_free_all(void);
void					garbage_update_ref(void *pold, void *pnew);
t_ref_list				*garbage_find_ref(void *p);
void					*malloc_wrapper(size_t size);
void					*realloc_wrapper(void *p, size_t new_size,
size_t old_size);

#endif
