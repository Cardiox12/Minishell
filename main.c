/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:00:27 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 06:38:07 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "reader.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"

void print(t_queue *HEAD)
{
	ft_printf("history : \n");
	while (HEAD != NULL)
	{
		ft_printf("%s\n", HEAD->token.value);
		HEAD = HEAD->next;
	}
}

int		main(void)
{
	// Here is the entrypoint
	char *line;
	t_queue *HEAD = NULL;

	line = NULL;
	while (1)
	{
		line = reader();
		if (line == NULL)
			break;
		enqueue(&HEAD, (t_token){0, line, 0});
		print(HEAD);
	}
	return (0);
}
