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
