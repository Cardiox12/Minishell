/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:57:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/16 13:47:08 by bbellavi         ###   ########.fr       */
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


int echo(char **args, char **env);
int cd(char **args, char **env);
int pwd(char **args, char **env);
int env(char **args, char **env);

# define __unused __attribute__((unused))
# define RAW_ARGUMENT "-n"
# define HOME "~"

#endif