/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 01:50:27 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/12 21:48:26 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			break ;
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
