/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:12:31 by selibrah          #+#    #+#             */
/*   Updated: 2019/05/18 22:33:14 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *src1;

	if (src == dst)
		return (dst);
	if (dst - src < (long)len)
	{
		src1 = malloc(len);
		ft_memcpy(src1, src, len);
		ft_memcpy(dst, src1, len);
		free(src1);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
