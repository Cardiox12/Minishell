/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:16:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/17 00:37:33 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int pwd(__unused char **args)
{
    char path[PATH_MAX];

    if (getcwd(path, PATH_MAX) == NULL)
        return (errno);
    ft_printf("%s\n", path);
    return (SUCCESS);
}