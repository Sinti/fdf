/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:18:17 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/18 18:55:49 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	char	*x;

	if ((x = (char *)malloc(n)) == NULL)
		return (NULL);
	x = ft_memcpy(x, (char *)from, n);
	to = ft_memcpy((char *)to, x, n);
	free(x);
	return (to);
}
