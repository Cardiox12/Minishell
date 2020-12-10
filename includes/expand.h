/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:15:05 by bbellavi          #+#    #+#             */
/*   Updated: 2020/12/10 01:35:35 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPAND_H
# define FT_EXPAND_H

# include "types.h"

# define SYM_TILDE '~'
# define TILDE "~"
# define TILDE_SLASH "~/"

char	*expand(const char *src, int tok_type);
char	*str_expand(char **src, int tok_type);
char	*find_variable(const char *key);
t_spair	get_items(const char *e_var);
char	*get_value(const char *e_var);
char	*get_key(const char *variable);
int		is_var_charset(int c);
int		is_bash_var(const char *s, t_slice slice);
char	*extract_and_replace(char *src, const char *value, t_slice slice);
char	*variable_replace(char **src, t_slice slice);
char	*str_replace(char **src, const char *key, const char *value);

#endif
