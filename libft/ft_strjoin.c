/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:55:29 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/21 04:18:30 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		x;
	char	*c;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = (size_t)ft_strlen((char *)s1);
	j = (size_t)ft_strlen((char *)s2);
	c = ft_strnew(i + j);
	if (c == NULL)
		return (NULL);
	x = 0;
	while (x < i + j)
	{
		if (x < i)
			c[x] = s1[x];
		else
			c[x] = s2[x - i];
		x++;
	}
	c[i + j] = '\0';
	return (c);
}
