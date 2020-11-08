
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
