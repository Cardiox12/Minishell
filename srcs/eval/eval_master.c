#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "eval.h"
#include "lexer.h"

extern char	**g_env;
t_queue		*g_queue;

// idee pour gerer pipes recursivement: systématiquement rentrer et utiliser les paramêtres input et output

int		is_arg(t_queue *queue)
{
	int		type;

	if (queue == NULL)
		return (0);
	type = queue->token.type;
	if (type == STRING || type == ARGUMENT 
		|| type == OPTION || type == RAW_STRING)
		return (1);
	else
		return (0);
}

int		is_output(t_queue *queue)
{
	int		type;

	if (queue == NULL)
		return (0);
	type = queue->token.type;
	if (type == REDIRECTION || type == PIPE) 
		return (1);
	else
		return (0);
}

t_queue		*craft_command(t_command *command, t_queue *queue)
{
	if (!(command->args = ft_stabmaker(6)))
		return (NULL);
	if (!(command->value = ft_strdup(queue->token.value)))
		return (NULL);
	if (!(add_to_dynamic_table(&(command->args), command->value)))
		return(NULL);
	if (!(command->path = get_path(command->value)))
		return (NULL);
	queue = queue->next;
	while (queue && is_arg(queue))
	{
		if (!(add_to_dynamic_table(&(command->args), queue->token.value)))
			return(NULL);
		queue = queue->next;
	}
	if (is_output(queue))
	{
		command->output_type = queue->token.type;
		queue = queue->next;
	}
	else
		command->output_type = -1;
	return (queue);
}

int		eval(t_queue *queue)
{
	t_command	command;
	int			piper_return;


	g_queue = queue;
	while (g_queue)
	{
		if (g_queue->token.type == COMMAND)
		{
			g_queue = craft_command(&command, g_queue);
//			print_s_command(&command);
			if (command.output_type == PIPE)
			{
				if ((piper_return = init_piper(&command)) == -1)
					return (-1);
			}
			else  
				fork_and_exec(command.path, command.args, &command, g_env);
			if (g_queue == NULL)
				return (0);
		}
	}
	return (0);
}