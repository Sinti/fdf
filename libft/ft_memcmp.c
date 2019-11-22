/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:09:42 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/05 02:20:49 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;
	int			ret;

	str1 = s1;
	str2 = s2;
	i = 0;
	ret = 0;
	while (i < n && ret == 0)
	{
		ret = ret + (unsigned char)*str1++ - (unsigned char)*str2++;
		i++;
	}
	return (ret);
}
