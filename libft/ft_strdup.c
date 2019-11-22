/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 03:50:06 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/05 02:35:09 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;
	int		u;

	u = 0;
	i = 0;
	while (src[i] != '\0')
		i = i + 1;
	ptr = (char*)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	ft_strcpy(ptr, src);
	return (ptr);
}
