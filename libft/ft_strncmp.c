/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 05:01:41 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/21 04:01:19 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	if (n != 0)
		ret = ret + (unsigned char)s1[i] - (unsigned char)s2[i];
	while ((unsigned char)s2[i] != '\0' && ret == 0 && i < (int)n)
	{
		if ((unsigned char)s1[i] != '\0')
		{
			ret = ret + (unsigned char)s1[i] - (unsigned char)s2[i];
			i++;
		}
		else
			ret = ret + (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	if ((unsigned char)s2[i] == '\0' && n != 0 && ret == 0)
		ret = ret + (unsigned char)s1[i] - (unsigned char)s2[i];
	return (ret);
}
