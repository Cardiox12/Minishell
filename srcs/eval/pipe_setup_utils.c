#include "eval.h"


int		get_pipeline_len(t_queue *queue)
{
	int		counter;

	counter = 0;
	while (queue && queue->token.type != OPERATOR)
	{
		if (queue->token.type == PIPE)
			counter++;
		queue = queue->next;
	}
	counter++;
	ft_printf("nbr of pipes: %d\n", counter);
	return (counter);
}

int		generate_pipe_array(int len)
{
	int		i;
	int		pipearray[len + 1][2];

	i = 0;
	while (i < len)
	{
		pipe(pipearray[i]);
		i++;	
	}
	pipearray[i][0] = -1;
	return (0);
}

int		generate_pipe_tab(int size)
{
	int		i;
//	int		pipefd[2];

	i = 0;
	if (!(g_pipe_array = (int**)malloc(sizeof(int*) * (size + 1))))
		return (-1);
	while (i < size)
	{
		if (!(g_pipe_array[i] = (int*)malloc(sizeof(int) * 2)))
			return (-1);
		pipe(g_pipe_array[i]);
/*		pipe(pipefd);
		g_pipe_array[i][0] = pipefd[0];
		g_pipe_array[i][1] = pipefd[1];
		pipefd[0] = 0;
		pipefd[1] = 0;*/
		i++;	
	}
	g_pipe_array[i] = NULL;
	return (i);
}