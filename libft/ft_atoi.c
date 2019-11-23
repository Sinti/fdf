/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:35:54 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/15 15:33:06 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		f;
	long	res;

	i = 0;
	res = 0;
	f = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' '
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
	{
		i++;
	}
	if (str[i] == '-')
		f = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * f;
	return (res);
}
