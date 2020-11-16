/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:18:25 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 02:16:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

size_t	string_arr_len(char **arr)
{
	size_t size;

	size = 0;
	while (arr[size] != NULL)
		size++;
	return (size);
}
