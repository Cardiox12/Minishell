#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "eval.h"
#include "lexer.h"

//extern t_queue  *g_queue;

int		pre_initialize_command(t_command *command)
{
	command->has_output_redirect = 0; // a intégrer dans une future fonction d'initialisation
	command->has_input_redirect = 0; // a intégrer dans une future fonction d'initialisation
	if (!(command->args = ft_stabmaker(6)))
		return (-1);
	if (!(command->value = ft_strdup(g_queue->token.value)))
		return (free_tab_ret_fail(&(command->args)));
	if (!(add_to_dynamic_table(&(command->args), command->value)))
		return (free_tab_string_ret_fail(&(command->value), &(command->args)));
	if (!(command->path = get_path(command->value)) && !(is_builtin(command->args)))
		return (free_tab_string_ret_fail(&(command->value), &(command->args)));
	g_queue = g_queue->next;
	if (g_queue == NULL)
		return (0);
	if (g_queue->token.type == PIPE)
	{
		command->output_type = PIPE;
		return (0);
	}
	return (0);
}

int			finish_command(t_command *command)
{
//	ft_printf("queue in finish: %s\n", g_queue->token.value);
	if (g_queue && g_queue->token.type == PIPE)
	{
		command->output_type = g_queue->token.type;
		g_queue = g_queue->next;
//		ft_printf("fish returns NULL\n");
		return (1);
	}
	else
		command->output_type = -1;
	if (g_queue && g_queue->token.type == OPERATOR)
	{
		g_queue = g_queue->next;
		return (1);
	}
	return (0);
}

int		get_redirects(int *count, t_command *command)
{
	while (g_queue && g_queue->token.type == REDIRECTION && (g_queue->token.value)[0] == '>')
	{
		if (get_output_redirections(command, g_queue) == -1)
			return (-1);
		g_queue = g_queue->next->next;
		(*count)++;
	}
	while (g_queue && g_queue->token.type == REDIRECTION && (g_queue->token.value)[0] == '<')
	{
		if (get_input_redirections(command, g_queue) == -1)
			return (-1);
		g_queue = g_queue->next->next;
		(*count)++;
	}
	return (0);
}

int		get_args(int *count, t_command *command)
{
	char	*expanded;

	while (g_queue && is_arg(g_queue))
	{
		if (g_queue->token.type == STRING || g_queue->token.type == ARGUMENT || g_queue->token.type == ENV_VARIABLE)
		{
			if (!(expanded = expand(g_queue->token.value)))
				return (free_command_ret_fail(command));
			if (!(add_to_dynamic_table(&(command->args), expanded)))
				return (free_command_ret_fail(command));
			ft_strdel(&expanded);
		}
		else
		{
			if (!(add_to_dynamic_table(&(command->args), g_queue->token.value)))
				return (free_command_ret_fail(command));
		}
		g_queue = g_queue->next;
		(*count)++;
	}
	return (0);
}

int		craft_command(t_command *command)
{
	int	count;
	int	diff;

	if ((pre_initialize_command(command)) == -1)
		return (-1);
	count = 0;
	while (g_queue != NULL && g_queue->token.type != PIPE)
	{
		diff = count;
		if ((get_args(&count, command)) == -1)
			return (-1);
		if ((get_redirects(&count, command)) == -1)
			return (-1);
		if (finish_command(command))
		{
//			g_queue = queue->next;
			break;
		}
/*		if (g_queue && (diff == count))
		{
			ft_printf("untracked value: %s\n", queue->token.value);
			ft_printf("symbols not tracked in craft_command\n");
			g_queue = g_queue->next;
		}
		if (g_queue)
			ft_printf("value %s\n", g_queue->token.value);*/
	}
	if (g_queue && g_queue->token.type == PIPE)
		g_queue = g_queue->next;
	return (0);
}