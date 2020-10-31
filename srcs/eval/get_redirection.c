#include "../../includes/eval.h"

static int		is_simple_redirect(t_queue *queue)
{
		if (ft_strlen(queue->token.value) == 1)
			return (1);
		else
			return (0);
}

/*static int		is_double_redirect(t_queue *queue)
{
		if (ft_strncmp(queue->token.value, ">>") == 0)
			return (1);
		else
			return (0);
}*/

int     get_output_redirections(t_command *command, t_queue *queue)
{
        int     fd;

		if (command->has_output_redirect == 0)
		{
			command->has_output_redirect = 1;
			if (!(command->output_redirection_files = ft_int_tab_maker(6)))
				return (-1);
		}
        if (is_simple_redirect(queue))
			fd = open(queue->next->token.value, O_RDWR | O_CREAT | O_TRUNC, 0666);
		else	
			fd = open(queue->next->token.value, O_RDWR | O_CREAT | O_APPEND, 0666);
		if (fd == -1)
		{
			perror("open");
			return (-1);
		}
		else
			add_to_dynamic_int_array(&(command->output_redirection_files), fd);
//		ft_printf("file: %s, fd: %d\n", queue->next->token.value, fd);
		return (0);
}


int     get_input_redirections(t_command *command, t_queue *queue)
{
        int     fd;

		if (command->has_input_redirect == 0)
		{
//			ft_printf("je suis la\n");
			command->has_input_redirect = 1;
			if (!(command->input_redirection_files = ft_int_tab_maker(6)))
				return (-1);
		}
		fd = open(queue->next->token.value, O_RDONLY, 0666);
		if (fd == -1)
		{
			ft_printf("bash: %s: No such file or directory\n", queue->next->token.value);
			return (-1);
		}
		else
			add_to_dynamic_int_array(&(command->input_redirection_files), fd);
		return (0);
}