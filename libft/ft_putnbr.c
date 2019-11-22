/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:29:07 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/21 05:00:38 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nblen(long nbr)
{
	long o;

	o = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr == 0)
		ft_putchar('0');
	while (nbr > 0)
	{
		nbr = nbr / 10;
		o = o * 10;
	}
	o = o / 10;
	return (o);
}

void			ft_putnbr(int n)
{
	long	l;
	int		d;
	long	nbr;

	nbr = n;
	l = nblen(nbr);
	if (n < 0)
		nbr = -nbr;
	while (l > 0)
	{
		d = nbr / l;
		ft_putchar(d + '0');
		nbr = nbr - d * l;
		l = l / 10;
	}
}
