/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:22:07 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/15 12:29:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNALS_H
# define FT_INTERNALS_h

# include <stddef.h>
# include <errno.h>
# include <string.h>
# include "ft_stdio.h"

size_t  arrlen(char **array);
void    cd_perror(char *path, int error);

#endif