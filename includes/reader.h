/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 04:27:38 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 05:16:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READER_H
# define FT_READER_H

# include <unistd.h>
# include <limits.h>
# include "ft_strings.h"
# include "ft_stdio.h"
#include "eval.h"

//extern char		**g_env;

int		reader(char **comand);

#endif
