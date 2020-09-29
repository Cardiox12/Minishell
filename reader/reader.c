#include "libft/libft.h"

int		mock_lexer(char *command)
{
	ft_printf(" --> command : %s\n", command);
	return (0);
}

/*sert a verifier si on a besoin d'utiliser la fonction de gestion des quotes*/
int		quote_finder(char *str)
{
	if (ft_strchr(str, '\'') == NULL && ft_strchr(str, '\"') == NULL)
		return (0);
	else
		return (1);
}

/*int			get_quote_type(char c)
{
	if (c == ''')
		return (1);
	else
		return (2);
}*/

/*gestion des quotes */
char	*handle_quotes(char **str)
{
	int		in_quote;
	char	*next_command;
	int		quote_char;
	int		i;
	int		len;

	i = 0;
	in_quote = 0;
//	quote_type = 0;
	len = ft_strlen(*str);
	while (i < len)
	{
		if ((*str)[i] == '\"' || (*str)[i] == '\'')
		{
			quote_char = (*str)[i];
			in_quote = 1;
			i++;
			while ((*str)[i] != quote_char)
			{
				i++;
				if (i >= len)
				{
					ft_printf("quote> ");
					get_next_line(0, &next_command);
					*str = ft_join_free_left(str, "\n");
					*str = ft_join_free_left(str, next_command);
					len = ft_strlen(*str);
				}
			}
		}
		i++;
	}
	return (*str);
}


char	*reader()
{
	char	*command;
	char	*cwd;

	while (1)
	{
		cwd = getcwd(NULL, 1);
		ft_printf("minishell@%s:", cwd);
		get_next_line(0, &command);
		if (quote_finder(command) == 1)
			command = handle_quotes(&command);

		/* remplacer fonction ci-dessous par le lexer : */
		mock_lexer(command);
		free(cwd);
		free(command);
	}
	return ("haha");
}

int		main(void)
{
	reader();
	return (0);
}
