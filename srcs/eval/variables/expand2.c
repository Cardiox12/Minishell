/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:36:03 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/11 00:45:11 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

char		*str_expand(char **src, int tok_type)
{
	char *old;

	old = *src;
	*src = expand(*src, tok_type);
	free(old);
	return (*src);
}
