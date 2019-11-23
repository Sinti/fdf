/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:55:11 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/15 15:44:15 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	i = 0;
	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
