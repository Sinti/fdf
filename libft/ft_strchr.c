/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:03:22 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/05 02:31:10 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	while (*s != '\0' && (unsigned char)*s++ != (unsigned char)c)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
	}
	return (NULL);
}
