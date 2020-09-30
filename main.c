/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:00:27 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 05:17:18 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"

int		main(void)
{
	// Here is the entrypoint
	char *line;

	line = NULL;
	while (1)
	{
		line = reader();
		if (line == NULL)
			break;
		ft_printf("%s\n", line);
	}
	return (0);
}
