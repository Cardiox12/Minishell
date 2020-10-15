/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:16:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/15 12:35:50 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int pwd(__unused char **args, __unused char **env)
{
    char path[PATH_MAX];

    if (getcwd(path, PATH_MAX) == NULL)
        return (errno);
    ft_printf("%s\n", path);
    return (SUCCESS);
}