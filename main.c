
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

#include "lexer.h"
#include "reader.h"
#include "parser.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"

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
	ft_printf("=============== TOKENS ===============\n");
	while (head != NULL)
	{
		ft_printf("(.type = %s, .value = %s, .index = %d)\n", get_type(head->token.type), head->token.value, head->token.index);
		head = head->next;
	}
	ft_printf("=======================================\n");
}

# include "builtins.h"
# include <limits.h>

int		main(__unused int argc, char *argv[], char *env[])
{
	// Here is the entrypoint
	// char *line;

	// line = NULL;
	// while (1)
	// {
	// 	line = reader();
	// 	t_queue *tokens = lexer(line);
	// 	print_queue(tokens);
	// 	if (parser(line, tokens) != 0)
	// 		ft_printf("minishell: parse error\n");
	// 	if (line == NULL)
	// 		break;
	// }
	char path[PATH_MAX];

	getcwd(path, PATH_MAX);
	ft_printf("%s\n", path);
	int err;
	if ( ( err = cd(argv, env) ) )
	{
		exit(err);
	}
	getcwd(path, PATH_MAX);
	ft_printf("%s\n", path);
	return (0);
}
