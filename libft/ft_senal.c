/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_senal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:09:15 by selibrah          #+#    #+#             */
/*   Updated: 2019/05/18 22:15:39 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_senal(char const *s, char c)
{
	int		i;
	int		j;
	char	**dst;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			;
		else if (s[i - 1] == c || i == 0)
			j++;
		i++;
	}
	dst = (char **)malloc((j + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	return (dst);
}
