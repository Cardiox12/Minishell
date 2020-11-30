/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 07:11:31 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/30 07:31:02 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVIRON_H
# define FT_ENVIRON_H

# include "eval.h"
# include "builtins.h"
# include "types.h"

# define BASIC_ENVIRON_SIZE 3

void	export_basic_environ(void);

static const t_string basic_environ[BASIC_ENVIRON_SIZE] = {
	"LS_COLORS=",
	"OLDPWD",
	"SHLVL=1"
};

#endif