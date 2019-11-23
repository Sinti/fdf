/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:52:37 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/08 02:45:43 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*res;

	i = 0;
	x = (unsigned char)c;
	res = (unsigned char *)s;
	while (i < n)
	{
		if (res[i] == x)
			return (res + i);
		i++;
	}
	return (NULL);
}
