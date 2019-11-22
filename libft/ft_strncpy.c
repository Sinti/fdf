/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:31:47 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/12 00:49:12 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	u;

	u = 0;
	while (u < len && src[u] != '\0')
	{
		dst[u] = src[u];
		u++;
	}
	while (u < len)
	{
		dst[u] = '\0';
		u++;
	}
	return (dst);
}
