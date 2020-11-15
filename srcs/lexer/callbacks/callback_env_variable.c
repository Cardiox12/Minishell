/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_env_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:34:08 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/15 21:43:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		callback_env_variable(t_lexer *lex)
{
	if (lex->input[lex->index] == SYM_ENV_VAR)
	{
		lex->index = get_env_variable(&lex->head, lex->input, lex->index);
		return (TRUE);
	}
	return (FALSE);
}