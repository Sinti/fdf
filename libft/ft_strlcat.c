/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 02:56:29 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/05 02:36:19 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int len_s1;
	int len_s2;
	int i;

	len_s1 = ft_strlen(dst);
	len_s2 = ft_strlen((char *)src);
	i = 0;
	while (i < len_s2 && i < (int)size - len_s1 - 1)
	{
		dst[len_s1 + i] = src[i];
		i++;
	}
	dst[len_s1 + i] = '\0';
	if ((int)size <= len_s1)
		return ((size_t)size + len_s2);
	else
		return ((size_t)len_s1 + len_s2);
}
