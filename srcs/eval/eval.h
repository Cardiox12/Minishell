/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:41:13 by tlucille          #+#    #+#             */
/*   Updated: 2020/10/05 11:48:23 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

typedef struct	s_token
{
	int			type;
	char		*value;
	size_t		index;
}				t_token;

typedef struct	s_queue
{
	struct s_queue	*next;
	t_token			token;
}				t_queue;

typedef struct	s_interpret
{
	char		*input;
	t_queue		tokens;
}				t_interpret;

