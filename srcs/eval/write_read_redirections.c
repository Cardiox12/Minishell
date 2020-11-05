/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_read_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:33:53 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/03 12:33:56 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void	write_redirections(t_command *command, char *buffer)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(buffer);
	while (command->output_redirection_files[i + 1] != -1)
	{
		close(command->output_redirection_files[i]);
		i++;
	}
	write(command->output_redirection_files[i], buffer, len);
	close(command->output_redirection_files[i]);
}

int		*read_redirections_pipe(t_command *command, int redirectpipe[2])
{
	int		i;
	char	*buffer;

	i = 0;
	while (command->input_redirection_files[i + 1] != -1)
	{
		close(command->input_redirection_files[i]);
		i++;
	}
	if (!(buffer = read_until_eof(command->input_redirection_files[i])))
		return ((void*)0);
	write(redirectpipe[1], buffer, ft_strlen(buffer));
	close(redirectpipe[1]);
	close(command->input_redirection_files[i]);
	return ((void*)0);
}

int		*read_redirections_nopipe(t_command *command, int pipe[2])
{
	int		i;
	char	*buffer;

	i = 0;
	while (command->input_redirection_files[i + 1] != -1)
	{
		close(command->input_redirection_files[i]);
		i++;
	}
	if (!(buffer = read_until_eof(command->input_redirection_files[i])))
		return ((void*)0);
	write(pipe[1], buffer, ft_strlen(buffer));
	close(command->input_redirection_files[i]);
	return ((void*)0);
}
