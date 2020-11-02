
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
	ft_printf("=============== TOKENS ===============\n");
	while (head != NULL)
	{
		ft_printf("(.type = %s, .value = %s, .index = %d)\n", get_type(head->token.type), head->token.value, head->token.index);
		head = head->next;
	}
	ft_printf("=======================================\n");
}

int		main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;

	char *line;

	line = NULL;

	if (!(ft_tab_copy(&g_env, envp)))
		return (-1);

	while (TRUE)
	{
		errno = 0;
		line = reader();
		t_queue *tokens = lexer(line);
		print_queue(tokens);
	}
	return (0);
}