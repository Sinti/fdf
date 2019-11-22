/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:45:37 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/21 04:00:15 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *c;

	if (s == NULL)
		return (NULL);
	c = ft_strnew(len);
	if (c == NULL)
		return (NULL);
	return (ft_strncpy(c, s + start, len));
}
