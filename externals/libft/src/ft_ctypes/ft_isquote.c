/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:52:01 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/16 03:06:04 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isquote(int c)
{
	return (c == '"' || c == '\'');
}
