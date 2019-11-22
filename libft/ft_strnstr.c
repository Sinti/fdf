/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 02:55:09 by selibrah          #+#    #+#             */
/*   Updated: 2019/05/18 18:00:59 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (find[0] == '\0')
		return ((char *)src);
	while (i < (int)len && src[i])
	{
		if (src[i] == find[j] && i < (int)len)
		{
			while (src[i] == find[j] && find[j] && i < (int)len)
			{
				i++;
				j++;
			}
			if (find[j] == '\0')
				return ((char *)src + i - j);
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
