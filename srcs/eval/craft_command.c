#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "eval.h"
#include "lexer.h"

t_queue		*pre_initialize_command(t_command *command, t_queue *queue)
{
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
//		return(queue->next);
		return(queue);
	}
	return (queue);
}

t_queue		*finish_command(t_command *command, t_queue *queue)
{
	ft_printf("queue in finish: %s\n", queue->token.value);
	if (queue && queue->token.type == PIPE)
	{
		command->output_type = queue->token.type;
		queue = queue->next;
		ft_printf("fish returns NULL\n");
		return (NULL);
	}
	else
		command->output_type = -1;
	if (queue && queue->token.type == OPERATOR)
	{
		queue = queue->next;
		return (NULL);
	}
	return (queue);
}

t_queue		*get_redirects(int *count, t_command *command, t_queue *queue)
{
	while (queue && queue->token.type == REDIRECTION && (queue->token.value)[0] == '>')
	{
		if (get_output_redirections(command, queue) == -1)
			return (NULL);
		queue = queue->next->next;
		(*count)++;
	}
	while (queue && queue->token.type == REDIRECTION && (queue->token.value)[0] == '<')
	{
		if (get_input_redirections(command, queue) == -1)
			return (NULL);
		queue = queue->next->next;
		(*count)++;
	}
	return (queue);
}

t_queue		*get_args(int *count, t_command *command, t_queue *queue)
{
	char	*expanded;

	while (queue && is_arg(queue))
	{
		if (queue->token.type == STRING || queue->token.type == ARGUMENT || queue->token.type == ENV_VARIABLE)
		{
			if (!(expanded = expand(queue->token.value)))
				return (NULL);
			if (!(add_to_dynamic_table(&(command->args), expanded)))
				return (NULL);
		}
		else
		{
			if (!(add_to_dynamic_table(&(command->args), queue->token.value)))
				return (NULL);
		}
		queue = queue->next;
		(*count)++;
	}
	return (queue);
}

t_queue		*craft_command(t_command *command, t_queue *queue)
{
	int	count;
	int	diff;

	if (!(queue = pre_initialize_command(command, queue)))
		return (NULL);
	count = 0;
	while (queue != NULL && queue->token.type != PIPE)
	{
		diff = count;
		if (!(queue = get_args(&count, command, queue)))
			return (NULL);
		if (!(queue = get_redirects(&count, command, queue)))
			return (NULL);
		if (!(finish_command(command, queue)))
		{
			queue = queue->next;
			break;
		}
		if (queue && (diff == count))
		{
			ft_printf("untracked value: %s\n", queue->token.value);
			ft_printf("symbols not tracked in craft_command\n");
			queue = queue->next;
		}
		if (queue)
			ft_printf("value %s\n", queue->token.value);
	}
	if (queue && queue->token.type == PIPE)
		queue = queue->next;
	return (queue);
}