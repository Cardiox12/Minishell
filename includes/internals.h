/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:22:07 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:38:15 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNALS_H
# define FT_INTERNALS_H

# include <stddef.h>
# include <errno.h>
# include <string.h>
# include "ft_objects.h"
# include "ft_stdio.h"

# define PWD "PWD"
# define PWD_SIZE 3

size_t	string_arr_len(char **array);
int		cd_perror(char *path, int error);
int		cd_error(char *str_error, int error);
void	free_env();
int		find_key(t_string_list *list, const char *key);

#endif
