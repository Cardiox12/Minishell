
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:00:27 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 09:21:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "lexer.h"
#include "reader.h"
#include "parser.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "eval.h"
#include "builtins.h"

char		**g_env = NULL;
int			g_exitstatus = 0;
t_queue		*g_queue = NULL;

char	*get_type(int type)
{
	switch (type)
	{
		case COMMAND:
			return ("COMMAND");
		case STRING:
			return ("STRING");
		case OPTION:
			return ("OPTION");
		case PIPE:
			return ("PIPE");
		case OPERATOR:
			return ("OPERATOR");
		case ENV_VARIABLE:
			return ("ENV_VARIABLE");
		case REDIRECTION:
			return ("REDIRECTION");
		case RAW_STRING:
			return ("RAW_STRING");
		case FILE_DESCRIPTOR:
			return ("FILE DESCRIPTOR");
		case ARGUMENT:
			return ("ARGUMENT");
		default:
			return ("");
	}
}

void	print_queue(t_queue *head)
{
	ft_printf("%-30s| %-30s| %-30s\n", "TYPE", "VALUE", "INDEX");
	while (head != NULL)
	{
		ft_printf("%-30s| %-30s| %-30d\n", get_type(head->token.type), head->token.value, head->token.index);
		head = head->next;
	}
}

int		main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;

	// char *line;

	// line = NULL;

	if (!(ft_tab_copy(&g_env, envp)))
		return (-1);

	t_string_list *list;

	string_list_create(&list);
	string_list_append(list, "Hello");
	string_list_append(list, "World");
	string_list_iter(list, puts);
	char **items = string_list_to_string_array(list);

	for (int index = 0 ; items[index] != NULL ; index++)
		puts(items[index]);
	// while (TRUE)
	// {
	// 	line = reader();
	// 	t_queue *tokens = lexer(line);
	// 	print_queue(tokens);

	// 	if (parser(line, tokens) != SUCCESS)
	// 	{
	// 		ft_printf("Error while parsing\n");
	// 		exit(0);
	// 	}
	// 	eval(tokens);
	// }
	return (0);
}