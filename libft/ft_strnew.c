/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:45:21 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/07 02:17:20 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = (char *)malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	while (i <= size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
