/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:24:54 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/28 16:19:26 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	char	buff[BUFF_SIZE];
	int		bytes;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		bytes = read(fd, buff, BUFF_SIZE);
		if (bytes == -1)
		{
			ft_putendl("Found wrong line length. Exiting.");
			return (0);
		}
		buff[bytes] = '\0';
		if (check(buff) == 1)
			mlx_start(buff);
		else
		{
			ft_putendl("Found wrong line length. Exiting.");
			return (0);
		}
	}
	else
		ft_putstr("usage :  ./fdf fileName.\n");
	return (0);
}
