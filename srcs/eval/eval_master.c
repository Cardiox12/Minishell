#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "eval.h"
#include "lexer.h"

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

// idee opti: rajouter is_builtin directement dans craft command


/* POUR TONY: dans cette commande, tu peux ajouter une ta fonction expand*/
t_queue		*craft_command(t_command *command, t_queue *queue)
{
	int	count; // those ints are used to see if some symbols are incorrectly assmilated
	int	diff;

	command->has_output_redirect = 0; // a intégrer dans une future fonction d'initialisation
	command->has_input_redirect = 0; // a intégrer dans une future fonction d'initialisation
	if (!(command->args = ft_stabmaker(6)))
		return (NULL);
	if (!(command->value = ft_strdup(queue->token.value)))
		return (NULL);
	if (!(add_to_dynamic_table(&(command->args), command->value)))
		return(NULL);
	if (!(command->path = get_path(command->value)) && !(is_builtin(command->args)))
		return (NULL);
	queue = queue->next;
	if (queue == NULL)
		return (queue);
	if (queue->token.type == PIPE)
	{
		command->output_type = PIPE;
		return(queue->next);
	}
	count = 0;
	while (queue != NULL && queue->token.type != PIPE)
	{
		diff = count;
		while (queue && is_arg(queue))
		{
			/* ICI tu peux ajouter ta fonction expand qui agira sur queue->token.value et après intégrer le résultat dans 
			le tableau dynamique avec la fonction ci-dessous: */
			if (!(add_to_dynamic_table(&(command->args), queue->token.value))) // du coup ici il faut remplacer queue->toke.value par le résultat d'expand
				return(NULL);
			queue = queue->next;
			count++;
		}
		while (queue && queue->token.type == REDIRECTION && (queue->token.value)[0] == '>')
		{
			if (get_output_redirections(command, queue) == -1)
				return (NULL);
			queue = queue->next->next;
			count++;
		}
		while (queue && queue->token.type == REDIRECTION && (queue->token.value)[0] == '<')
		{
			if (get_input_redirections(command, queue) == -1)
				return (NULL);
			queue = queue->next->next;
			count++;
		}
		if (queue && queue->token.type == PIPE)
		{
			command->output_type = queue->token.type;
			queue = queue->next;
			break;
//			count++;
		}
		else
			command->output_type = -1;
		if (queue && (diff == count))
		{
			ft_printf("untracked value: %s\n", queue->token.value);
			ft_printf("symbols not tracked in craft_command\n");
			queue = queue->next;
		}
		if (queue)
			ft_printf("value %s\n", queue->token.value);
	}
//	if (command->output_type != PIPE)
//		command->output_type = -1;
	return (queue);
}

int		eval(t_queue *queue)
{
	t_command	command;
	int			piper_return;


	g_queue = queue;
//	while (g_queue)
//	{
		if (g_queue->token.type == COMMAND)
		{
			g_queue = craft_command(&command, g_queue);
			print_s_command(&command);
			if (command.output_type == PIPE)
			{
				if ((piper_return = init_piper(&command)) == -1)
					return (-1);
			}
			else
			{
				if (is_builtin(command.args))
					simple_builtin(&command);
				else
					fork_and_exec(&command);
			}
			if (g_queue == NULL)
				return (0);
			else
			{
				ft_printf("untracked symbol in eval %s\n", g_queue->token.value);
			}
			
		}
//	}
//	ft_printf("out of eval\n");
	return (0);
}