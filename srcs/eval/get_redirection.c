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
		if (ft_strcmp(queue->token.value, ">>") == 0)
			return (1);
		else
			return (0);
}*/

int     get_redirections(t_command *command, t_queue *queue)
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
			add_to_dynamic_int_array(&command->output_redirection_files, fd);
		return (0);
}