/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:18:32 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/09 16:19:12 by tlucille         ###   ########.fr       */
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

void		sigquit_handle(void)
{
	static int i;

	i++;
	if (g_in_eval)
	{
		if (i == 1)
			write(1, "Quit: 3\n", 8);
		else
			write(1, "\\Quit: 3\n", 9);
		g_exitstatus = 131;
	}
	else
		write(1, "\b \b", 3);
}

void		do_exit(int status)
{
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

void		sigterm_handler(int sig)
{
	int			nbr;

	(void)sig;
	if (g_in_eval)
		nbr = 130;
	else
		nbr = 1;
	exit(nbr);
}

void		signal_handler(int sig)
{
	int status;

	if (sig == SIGQUIT)
		sigquit_handle();
	else
	{
		kill(g_pid_to_kill, SIGTERM);
		while (wait(&status) == -1)
			continue;
		if (WIFEXITED(status))
			g_exitstatus = (WEXITSTATUS(status));
		g_pid_to_kill = fork();
		if (g_pid_to_kill == 0)
		{
			signal(SIGTERM, sigterm_handler);
			if (g_exitstatus == 130)
				write(1, "\n", 1);
			else
				write(1, "\b\b  \n", 5);
			run_shell();
			exit(1);
		}
		else
			signal(SIGINT, signal_handler);
	}
}
