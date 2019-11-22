/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 22:47:07 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/21 05:01:03 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbrlen(long nbr, int fd)
{
	long o;

	o = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_fd('-', fd);
	}
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		o = o * 10;
	}
	o = o / 10;
	return (o);
}

void			ft_putnbr_fd(int n, int fd)
{
	long	l;
	int		d;
	long	nbr;

	nbr = n;
	l = nbrlen(nbr, fd);
	if (n < 0)
		nbr = -nbr;
	while (l > 0)
	{
		d = nbr / l;
		ft_putchar_fd(d + '0', fd);
		nbr = nbr - d * l;
		l = l / 10;
	}
}
