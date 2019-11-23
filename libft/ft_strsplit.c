/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:38:27 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/14 18:33:49 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) && s[i + 1])
			j++;
		i++;
	}
	j++;
	return (j);
}

static	size_t	ft_wlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c)
		s++;
	while ((s[i] != c) && (s[i]))
	{
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	j;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_countsplit(s, c);
	res = (char **)malloc((j + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (k < j)
	{
		while (s[i] == c)
			s++;
		res[k] = ft_strsub(s, 0, ft_wlen(s, c));
		s = s + ft_wlen(s, c);
		k++;
	}
	res[k] = NULL;
	return (res);
}
