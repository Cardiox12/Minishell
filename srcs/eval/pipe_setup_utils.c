#include "eval.h"

int		close_useless_pipes(int pipe_index_1, int pipe_index_2, int index)
{
	int i;

	i = index;
	while (g_pipe_array[i])
	{
		if (i != pipe_index_1 && i != pipe_index_2)
			close_pipe(g_pipe_array[i]);
		i++;
	}
	return (i);
}

int		close_pipe(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}

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
//	ft_printf("nbr of pipes: %d\n", counter);
	return (counter);
}

int		generate_pipe_tab(int size)
{
	int		i;
//	int		pipefd[2];

	i = 0;
	size++;
	if (!(g_pipe_array = (int**)malloc(sizeof(int*) * (size + 2))))
		return (-1);
	while (i < size)
	{
		if (!(g_pipe_array[i] = (int*)malloc(sizeof(int) * 2)))
			return (-1);
		pipe(g_pipe_array[i]);
		i++;	
	}
	g_pipe_array[i] = NULL;
	return (i);
}