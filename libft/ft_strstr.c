/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:41:23 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/08 02:24:42 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *ss)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)s;
	s2 = (char *)ss;
	len = ft_strlen(s2);
	if (len == 0)
		return (s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j])
		{
			if (j == (len - 1))
				return (s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
