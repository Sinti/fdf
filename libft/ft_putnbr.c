/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:44:35 by relkassm          #+#    #+#             */
/*   Updated: 2019/04/05 02:37:29 by relkassm         ###   ########.fr       */
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

static	int		ft_lenght(int nb)
{
	int		i;

	i = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void			ft_putnbr(int n)
{
	char	r;
	int		x;

	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	x = ft_lenght(n) - 1;
	while (x >= 0)
	{
		r = n / ft_power(10, x) + '0';
		n = n % ft_power(10, x);
		x--;
		ft_putchar(r);
	}
}
