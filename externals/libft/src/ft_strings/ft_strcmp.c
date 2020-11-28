/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:45:58 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/28 01:56:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char c1;
	unsigned char c2;

	c1 = *s1;
	c2 = *s2;
	while (c1 == c2)
	{
		if (c1 == '\0')
			return (c1 - c2);
		c1 = *s1++;
		c2 = *s2++;
	}
	return (c1 - c2);
}
