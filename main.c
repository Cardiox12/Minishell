
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

void		sigquit_handle(void)
{
	static int i;
	char c;

	i++;
	c = 127;
	if (g_in_eval)
	{
		if (i == 1)
			write(1, "Quit: 3\n", 8);
		else
			write(1, "\\Quit: 3\n", 9);
		g_exitstatus = 131;
	}
	else
		write(1, "\b  \b", 4);
}

void		signal_handler(int sig)
{
	int status;

	if (sig == SIGQUIT)
		sigquit_handle();
	else
	{	
		kill(g_pid_to_kill, SIGKILL);
		g_pid_to_kill = fork();
		if (g_pid_to_kill == 0)
		{
			if (g_in_eval)
				write(1, "\n", 1);
			else
				write(1, "\b\b  \n", 5);
			g_exitstatus = 1;
			run_shell();
			exit(1);
		}
		else
		{
			signal(SIGINT, signal_handler);
			wait(&status);
		}
	}
}

void		run_shell()
{
	char	*line;
	t_queue *tokens;

	while (TRUE)
	{
		reader(&line);
		tokens = lexer(line);
		// print_queue(tokens);~~

		if (parser(line, tokens) != SUCCESS)
			ft_printf("Error while parsing\n");
		else
			eval(tokens);
	}
}

/*void		signal_handler(int sig)
{
	int status;

	sig = sig + 1 - 1;
	kill(g_pid_to_kill, SIGKILL);
	g_pid_to_kill = fork();
	if (g_pid_to_kill == 0)
	{
		write(1, "\n", 1);
		run_shell();
		exit(1);
	}
	else
		signal(SIGINT, signal_handler);
	wait(&status);
}*/

// need to kill the child
int		main(int argc, char *argv[], char *envp[])
{
	int status;

	(void)argc;
	(void)argv;
	if (!(ft_tab_copy(&g_env, envp)))
		return (-1);
//	run_shell();
	g_pid_to_kill = fork();
	if (g_pid_to_kill == 0)
		run_shell();
	else
		signal(SIGINT, signal_handler);
	wait(&status);
	return (0);
}