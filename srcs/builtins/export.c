/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:54:55 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/13 22:15:50 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "internals.h"
#include "internal_errors.h"

static int find_key(t_string_list *list, const char *key)
{
    const size_t key_size = ft_strlen(key);
    size_t index;

    index = 0;
    while (index < list->length)
    {
        if (ft_strncmp(list->items[index], key, key_size) == 0)
            return (index);
        index++;
    }
    return (NOT_FOUND);
}

static char *make_variable(const char *key)
{
    size_t  key_size;
    char    *variable;

    key_size = ft_strlen(key);
    variable = malloc(sizeof(char) * (key_size + 1 + 1));
    if (variable == NULL)
        return (NULL);
    ft_strcpy(variable, key);
    variable[key_size] = '=';
    variable[key_size + 1] = '\0';
    return (variable);
}

static int export_key_value(char *variable)
{
    t_string_list   *list;
    int             index;
    char            *key;

    list = NULL;
    key = get_key(variable);
    if (key == NULL)
        return (ERR_MALLOC_FAILED);
    string_list_create_from(&list, g_env, string_arr_len(g_env));
    if (list == NULL)
        return (ERR_MALLOC_FAILED);
    if ((index = find_key(list, key)) != NOT_FOUND)
    {
        free(key);
        free(list->items[index]);
        if ((list->items[index] = ft_strdup(variable)) == NULL)
            return (ERR_MALLOC_FAILED);
    }
    else
    {
        free(key);
        if (string_list_append(list, variable) == ERR_MEM_ALLOC_FAILED)
            return (ERR_MALLOC_FAILED);
    }
    g_env = string_list_to_string_array(list);
    string_list_delete(&list);
    return (SUCCESS);
}

static int export_key(char *key)
{
    t_string_list   *list;
    int             index;
    char            *variable;

    list = NULL;
    string_list_create_from(&list, g_env, string_arr_len(g_env));
    if (list == NULL)
        return (ERR_MALLOC_FAILED);
    index = find_key(list, key);
    if (index != NOT_FOUND)
        return (FAILURE);
    variable = make_variable(key);
    if (variable == NULL)
    {
        string_list_delete(&list);
        return (ERR_MALLOC_FAILED);
    }
    if (string_list_append(list, variable) == ERR_MEM_ALLOC_FAILED)
    {
        string_list_delete(&list);
        return (ERR_MALLOC_FAILED);
    }
    free(variable);
    g_env = string_list_to_string_array(list);
    string_list_delete(&list);
    return (SUCCESS);
}

static int export_none()
{
    t_spair items;
    size_t  index;

    index = 0;
    while (g_env[index] != NULL)
    {
        items = get_items(g_env[index]);
        if (items.key == NULL && items.value == NULL)
            return (ERR_MALLOC_FAILED);
        ft_printf("declare -x %s=\"%s\"\n", items.key, items.value);
        free_spair(items);
        index++;
    }
    return (SUCCESS);
}

int export(char **args)
{
    char *variable;

    variable = args[1];
    if (variable == NULL)
        return (export_none());
    else if (ft_isdigit(*variable))
    {
        print_internal_error("export", variable, ERROR_NOT_VALID_IDENTIFIER, TRUE);
        return (FAILURE);
    }
    else if (ft_strchr(variable, SYM_EQUAL) != NULL)
        return (export_key_value(variable));
    else
        return (export_key(variable));
}