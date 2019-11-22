/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 04:37:14 by selibrah          #+#    #+#             */
/*   Updated: 2019/05/18 22:10:17 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	getnextword(char const *s, char c, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strsub(s, j, i - j);
			k++;
		}
	}
	tab[k] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char **tab;

	if (s == NULL)
		return (NULL);
	tab = ft_senal(s, c);
	if (tab == NULL)
		return (NULL);
	getnextword(s, c, tab);
	return (tab);
}
