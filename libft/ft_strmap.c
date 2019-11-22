/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:45:00 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/21 04:17:22 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*c;

	if (s == NULL)
		return (NULL);
	c = ft_strnew((size_t)ft_strlen((char *)s));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c[i] = f(s[i]);
		i++;
	}
	return (c);
}
