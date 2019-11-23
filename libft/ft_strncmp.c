/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:13:18 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/08 02:48:58 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s, const char *ss, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)s;
	s2 = (unsigned char *)ss;
	if (n == 0)
		return (0);
	while ((s1[i] && s2[i] && (s1[i] == s2[i])) && i + 1 < n)
		i++;
	return (s1[i] - s2[i]);
}
