/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 02:05:49 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/12 21:54:25 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tr;
	size_t	i;

	if (!s)
		return (NULL);
	tr = (char *)malloc(len + 1);
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tr[i] = s[start];
		i++;
		start++;
	}
	tr[i] = '\0';
	return (tr);
}
