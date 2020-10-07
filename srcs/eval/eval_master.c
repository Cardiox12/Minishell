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
			if (!(command.args = ft_stabmaker(6)))
				return (-1);
			if (!(command.value = ft_strdup(queue->token.value)))
				return (-1);
			if (!(add_to_dynamic_table(&(command.args), command.value)))
				return(-1);
			queue = queue->next;
			while (queue && is_arg(queue))
			{
				if (!(add_to_dynamic_table(&(command.args), queue->token.value)))
					return(-1);
				queue = queue->next;
			}
			if (ft_strncmp("ls", command.value, 2) == 0)
				command.path = ft_strdup("/bin/ls");
			if (ft_strncmp("wc", command.value, 2) == 0)
				command.path = ft_strdup("usr/bin/wc");
//			print_s_command(&command);	
			if (queue == NULL)
				fork_and_exec(command.path, command.args, &command, g_env);
			else
			{
				ft_printf("not a simple command\n");
				return (0);
			}
		}
	}
	return (0);
}