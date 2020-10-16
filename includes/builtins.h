/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:57:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/16 15:53:25 by bbellavi         ###   ########.fr       */
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

typedef struct  s_spair
{
    char *key;
    char *value;
}               t_spair;

int echo(char **args, char **envp);
int cd(char **args, char **envp);
int pwd(char **args, char **envp);
int env(char **args, char **envp);
int export(char **args, char **envp);

# define __unused __attribute__((unused))
# define RAW_ARGUMENT "-n"
# define HOME "~"

#endif