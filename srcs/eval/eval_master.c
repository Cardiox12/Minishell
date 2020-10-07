#include "libft/ft_libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "eval.h"
#include "lexer.h"

extern char	**g_env;

// idee pour gerer pipes recursivement: systématiquement rentrer et utiliser les paramêtres input et output

int		is_arg(t_queue *queue)
{
	int		type;

	type = queue->token.type;
	if (type == STRING || type == ARGUMENT 
		|| type == OPTION || type == RAW_STRING)
		return (1);
	else
		return (0);
}

int		eval(t_queue *queue)
{
	t_command	command;


//	if (!(command = (t_command)malloc(sizeof(t_command))))
//		return (-1);
	while (queue)
	{
		if (queue->token.type == COMMAND)
		{
			/* get the necessary infos about the command */
			if (!(command.args = ft_stabmaker(6)))
				return (-1);
			if (!(command.value = ft_strdup(queue->token.value)))
				return (-1);

			/* command name needs to be the first of the arg array */
			if (!(add_to_dynamic_table(&(command.args), command.value)))
				return(-1);
			queue = queue->next;

			/* while the tokens are arguments (options, strings, etc...),
			add them to the dedicated array */
			while (queue && is_arg(queue))
			{
				if (!(add_to_dynamic_table(&(command.args), queue->token.value)))
					return(-1);
				queue = queue->next;
			}

			/* get the binary's full path */
			if (!(command.path = get_path(command.value)))
				return (-1);

			/* if it's a simple command, run it */
			if (queue == NULL)
				fork_and_exec(command.path, command.args, &command, g_env);
			else
			{
				/* to do */
				ft_printf("not a simple command\n");
				return (0);
			}
		}
	}
	return (0);
}