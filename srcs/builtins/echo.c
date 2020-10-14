/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:11:29 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/14 19:13:19 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char *strcjoin(char **strings, char *charset)
{
    size_t index;
    char *string;
    char *previous;

    index = 0;
    string = ft_strdup("");
    while (strings[index] != NULL)
    {
        previous = string;
        string = ft_strjoin(string, strings[index]);
        free(previous);
        if (string == NULL)
            return (NULL);

        if (strings[index + 1] != NULL)
        {
            previous = string;
            string = ft_strjoin(string, charset);
            free(previous);
            if (string == NULL)
                return (NULL);
        }
        index++;
    }
    return (string);
}

static int is_endl(const char *argument)
{
    if (argument != NULL)
    {
        if (ft_strncmp(argument, RAW_ARGUMENT, 2) == 0)
            return (TRUE);
    }
    return (FALSE);
}

int     echo(char **args, __unused char **env)
{
    size_t  index;
    int     endl;
    char    *string;

    index = 1;
    endl = TRUE;
    if (is_endl(args[index]))
    {
        endl = FALSE;
        index++;
    }
    string = strcjoin(&args[index], " ");
    if (string == NULL)
        return (FAILURE);
    if (endl)
        ft_putendl_fd(string, 1);
    else
        ft_putstr_fd(string, 1);
    return (SUCCESS);
}