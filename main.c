/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:00:27 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/23 12:40:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
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
int			g_pid_to_kill = 0;
int			g_in_eval = 0;
int			g_quote_parity_error = 0;

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

int		run_shell(void)
{
	char	*line;
	t_queue *tokens;

	g_flawed = 0;
	while (TRUE)
	{
		g_quote_parity_error = 0;
		if (reader(&line) == -1)
			return (-1);
		tokens = lexer(line);
		print_queue(tokens);
		if (g_quote_parity_error)
			ft_putstr_fd("minishell: Error quote is not closed\n", 2);
		else if (parser(line, tokens) == SUCCESS)
		{
			g_in_eval = 1;
			if (eval(tokens) == -1)
				return (-1);
			g_in_eval = 0;
		}
		free(line);
		queue_delete(&tokens);
	}
}

void	wait_and_exit(void)
{
	int status;

	wait(&status);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

int		main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	if (!(ft_tab_copy(&g_env, envp)))
		return (-1);
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGTERM, SIG_IGN);
	g_pid_to_kill = fork();
	if (g_pid_to_kill == 0)
	{
		signal(SIGTERM, sigterm_handler);
		if (run_shell() == -1)
		{
			ft_freetab(&g_env);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait_and_exit();
	return (0);
}
