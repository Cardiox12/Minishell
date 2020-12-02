/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <tlucille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:21:28 by tlucille          #+#    #+#             */
/*   Updated: 2020/11/30 19:21:30 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		setup_out_redirects(t_command *command,
			int out_redirect[2], int outpipe[2])
{
	close(outpipe[0]);
	if (command->has_output_redirect == 1)
	{
		close(out_redirect[0]);
		dup2(out_redirect[1], 1);
		close(out_redirect[1]);
	}
	else if (command->output_type == PIPE)
		dup2(outpipe[1], 1);
	close(outpipe[1]);
	return (0);
}
