/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:57:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/14 18:56:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H

# include <stddef.h>
# include "ft_ctypes.h"
# include "ft_stdio.h"
# include "ft_strings.h"


int echo(char **args, char **env);

# define __unused __attribute__((unused))
# define RAW_ARGUMENT "-n"

#endif