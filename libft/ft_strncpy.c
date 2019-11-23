/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:01:04 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/08 02:46:48 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *des, const char *src, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		if (src[i])
			des[i] = src[i];
		else
			break ;
		i++;
	}
	while (i < l)
	{
		des[i] = '\0';
		i++;
	}
	return (des);
}
