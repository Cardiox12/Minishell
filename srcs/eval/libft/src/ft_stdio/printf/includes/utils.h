/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:49:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/29 21:37:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include "ft_strings.h"
# include "ft_stdlib.h"
# include "parser.h"

int		ft_isdigit(unsigned char c);
int		ft_issymbol(char c);
int		ft_abs(int number);
char	*ft_strchrset(const char *s, const char *charset);
int		ft_is_negative(t_state *state);
int		ft_is_zero(t_state *state);

#endif
