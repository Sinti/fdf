/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 01:16:36 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/12 21:39:39 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ns;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	ns = (char *)malloc(i + 1);
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ns[i] = f(s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
