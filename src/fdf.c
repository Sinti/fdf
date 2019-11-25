/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:06:04 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/25 15:47:07 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			print(char *buff)
{
	t_win	w;

	w.hi = count_height(buff);
	w.wi = count_width(buff);
	w.x = 0;
	w.y = 0;
	w.jj = 0;
	w.zmo = 1;
	w.zm = w.zmo;
	w.winx = 1000;
	w.winy = 1000;
	w.pr = 1;
	w.z = 1;
	w.table = store(buff);
	w.mlx_ptr = mlx_init();
	w.buff = buff;
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.winx, w.winy, "FDF");
	w.img_ptr = mlx_new_image(w.mlx_ptr, 500, 500);
	w.winx = 500 + w.wi * w.zm;
	w.winy = 500 + w.hi * w.zm;
	mlx_hook(w.win_ptr, 2, 0, keypress, &w);
	drawmap(buff, w.table, &w);
	ft_putstr("finish\n");
	mlx_loop(w.mlx_ptr);
}

static void		rotation(int *x, int *y, int *z, t_win *w)
{
	int		previous_x;
	int		previous_y;
	int		previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	*x = previous_x;
	*y = previous_y * cos(0.45) + previous_z * sin(0.45);
	*z = -previous_y * sin(0.45) + previous_z * cos(0.45);
}

int				keypress(int key, t_win *w)
{
	if (key == 13)
		w->jj = 1 - w->jj;
	if (key == 6)
		w->zm = w->zm + 1;
	else if (key == 0)
		w->z = w->z + 1;
	else if (key == 1)
		w->z = w->z - 1;
	else if (key == 34)
		w->pr = w->pr * -1;
	else if (key == 12)
		w->rx = w->rx * -1;
	else if (key == 7 && w->zm > 1)
		w->zm = w->zm - 1;
	else if (key == 124)
		w->x = w->x + 30;
	else if (key == 125)
		w->y = w->y + 30;
	else if (key == 123)
		w->x = w->x - 30;
	else if (key == 126)
		w->y = w->y - 30;
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	drawmap(w->buff, w->table, w);
	return (0);
}

void			drawmap(char *buff, int **t, t_win *w)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	w->mx = w->x * (1 - w->jj);
	w->my = w->y * (1 - w->jj);
	while (j < w->hi)
	{
		i = 0;
		while (i < w->wi)
		{
			if (i != w->wi - 1)
				line((i) * w->zm + w->mx, j * w->zm + w->my, (i + 1) * w->zm\
						+ w->mx, j * w->zm + w->my, w, t[j][i] == 0 && \
						t[j][i + 1] == 0 ? 0xFFFFFF : 0xFF0000, t, w->zm);
			if (j != w->hi - 1)
				line(i * w->zm + w->mx, j * w->zm + w->my, i * w->zm + w->mx,
						(j + 1) * w->zm + w->my, w, t[j][i] == 0 && \
						t[j + 1][i] == 0 ? 0xFFFFFF : 0xFF0000, t, w->zm);
			i++;
		}
		j++;
	}
}
