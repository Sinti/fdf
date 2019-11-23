/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:45:46 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/08 01:52:58 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_power(int n, int p)
{
	int		i;
	int		x;

	x = 1;
	i = 0;
	while (i < p)
	{
		x = x * n;
		i++;
	}
	return (x);
}

static	size_t	ft_lenght(int nb)
{
	size_t	i;

	i = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	int		f;
	int		len;
	char	*res;
	long	r;

	i = 0;
	r = (long)n;
	f = (r < 0) ? -1 : 1;
	len = ft_lenght(r);
	res = malloc(len + 2);
	if (res == NULL)
		return (NULL);
	if (f == -1)
		res[i++] = '-';
	r = r * f;
	while (len-- > 0)
	{
		res[i++] = r / ft_power(10, len) + '0';
		r = r % ft_power(10, len);
	}
	res[i++] = '\0';
	return (res);
}
