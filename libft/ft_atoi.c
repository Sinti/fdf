/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:29:06 by selibrah          #+#    #+#             */
/*   Updated: 2019/05/18 21:48:51 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	test(const char *str, int i)
{
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		return (1);
	return (0);
}

static	int	norm(const char *str, int j, int i, long nb)
{
	while (str[i] && str[i] < 58)
	{
		if ((str[i] == '-' || test(str, i)) && j > 0)
			j = (str[i] == '-' ? -j : j);
		else if (ft_isdigit(str[i]))
		{
			if (nb > nb * 10 + str[i] - '0')
				return (j < 0 ? 0 : -1);
			nb = nb * 10 + str[i] - '0';
			if (!ft_isdigit(str[i + 1]))
				return (nb * j);
		}
		else if (ft_isdigit(str[i - 1]) || str[i - 1] == '-')
			return (nb * j);
		else if ((str[i] < 14 && str[i] > 8) || str[i] == 32)
			;
		else
			return (0);
		i++;
	}
	return (nb * j);
}

int			ft_atoi(const char *str)
{
	long	nb;
	int		i;
	int		j;

	i = 0;
	j = 1;
	nb = 0;
	return (norm(str, j, i, nb));
}
