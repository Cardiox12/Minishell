/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:57:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/17 00:36:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H

# include <string.h>
# include <stddef.h>
# include <errno.h>
# include <limits.h>
# include "ft_ctypes.h"
# include "ft_stdio.h"
# include "ft_strings.h"
# include "ft_objects.h"
# include "eval.h"

typedef struct  s_spair
{
    char *key;
    char *value;
}               t_spair;

int echo(char **args);
int cd(char **args);
int pwd(char **args);
int env(char **args);
int export(char **args);

# define __unused __attribute__((unused))
# define RAW_ARGUMENT "-n"
# define HOME "~"

#endif