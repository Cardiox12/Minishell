#include "eval.h"

/*int		setup_pipeline(int len, t_command *command)
{

}*/

int		initialize_pipeline(t_command *command)
{
	int		pipe_len;

	(void)command; // a virer
	pipe_len = get_pipeline_len(g_queue);
	pipe_len = get_pipeline_len(g_queue);
	generate_pipe_tab(pipe_len);
	return (0);
}