
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

char		**g_env = NULL;

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

/* ajout du tableau d'env dans le main */
int		main(int ac, char **av, char *env[])
{
	if (!(ft_tab_copy(&g_env, env)))
		return (FAILURE);
#ifdef MASTER
	char *line;

	line = NULL;
	while (TRUE)
	{
		line = reader();
		t_queue *tokens = lexer(line);
		if (parser(line, tokens) != 0)
		{
			ft_printf("minishell: parse error\n");
			return (EXIT_FAILURE);
		}
		eval(tokens);
		if (line == NULL)
			break;
	}
#endif

#ifdef BUILTINS

# include "builtins.h"
# include <limits.h>
# include <string.h>

int		main(__unused int argc, __unused char *argv[], char *envp[])
{
	if (ft_tab_copy(&g_env, envp) == NULL)
		return (FAILURE);
	int ret = builtins_call(++argv);
	if (ret != 0)
		ft_printf("Error\n");
	return (0);
}
#endif


	return (0);
}
