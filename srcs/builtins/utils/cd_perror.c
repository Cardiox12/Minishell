/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:24:01 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/15 12:29:07 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	cd_perror(char *path, int error)
{
	ft_printf("cd: %s: %s\n", strerror(error), path);
}