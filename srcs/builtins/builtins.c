/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:40:20 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/10 15:01:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int builtins_call(t_command *cmd)
{
    size_t size;
    size_t index;
    size_t status;

    index = 0;
    if (*cmd->args == NULL)
        return (ERR_BUILTIN_NOT_FOUND);
    size = ft_strlen(*cmd->args);
    while (index < BUILTINS_SIZE)
    {
        if (ft_strncmp(g_builtins[index].func_name, *cmd->args, size) == 0)
        {
            status = g_builtins[index].callback(cmd->args);
            g_exitstatus = status;
            if (status == ERR_MEM_ALLOC_FAILED)
            {
                g_exitstatus = FAILURE;
                free_command(cmd);
            }
            return (g_exitstatus);
        }
        index++;
    }
    return (ERR_BUILTIN_NOT_FOUND);
}