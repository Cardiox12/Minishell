/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 04:28:46 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/30 04:49:43 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

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

/*texte a afficher en fonction de si c'est simple ou double quote*/
void	print_right_quote(char quote_char)
{
		if (quote_char == '\"')
			ft_printf("dquote> ");
		else
			ft_printf("quote> ");
}

/*gestion des quotes */
char	*handle_quotes(char **str)
{
	char	*next_command;
	int		quote_char;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(*str);
	while (i < len)
	{
		if ((*str)[i] == '\"' || (*str)[i] == '\'')
		{
			quote_char = (*str)[i];
			i++;
			while ((*str)[i] != quote_char)
			{
				i++;
				if (i >= len)
				{
					print_right_quote(quote_char);
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

/*gestion des backslash en fin de commande*/
char	*back_slash_handle(char **command)
{
	char	*next_command;
	int		len;

	len = ft_strlen(*command);
	while ((*command)[len - 1] == '\\')
	{
		ft_printf("> ");
		get_next_line(0, &next_command);
		*command = ft_join_free_left(command, next_command);
		if (quote_finder(*command) == 1)
			*command = handle_quotes(command);
		len = ft_strlen(*command);
	}
	return (*command);
}

char	*reader()
{
	char	*command;
	char	cwd[PATH_MAX];
	int		len;

	while (1)
	{
		ft_bzero(cwd, PATH_MAX);
		getcwd(cwd, PATH_MAX);
		ft_printf("minishell@%s:", cwd);
		get_next_line(0, &command);
		if (quote_finder(command) == 1)
			command = handle_quotes(&command);
		len = ft_strlen(command);
		if (command[len - 1] == '\\')
			command = back_slash_handle(&command);

		/* remplacer fonction ci-dessous par le lexer : */
		mock_lexer(command);
		free(command);
	}
	return ("haha");
}
