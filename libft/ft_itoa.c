/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:21:14 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/21 05:03:19 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbln(long nbr)
{
	int o;

	o = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		o++;
	}
	if (nbr == 0)
		o++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		o++;
	}
	return (o);
}

char			*ft_itoa(int n)
{
	int		l;
	int		d;
	long	nbr;
	char	*nb;

	nbr = n;
	l = nbln(nbr);
	nb = (char *)malloc((l + 1) * sizeof(char));
	if (nb == NULL)
		return (NULL);
	if (n < 0)
		nbr = -nbr;
	if (n == 0)
		nb[0] = '0';
	nb[l--] = '\0';
	while (l >= 0)
	{
		d = nbr / 10;
		nb[l] = nbr - d * 10 + '0';
		l--;
		nbr = d;
	}
	if (n < 0)
		nb[0] = '-';
	return (nb);
}
