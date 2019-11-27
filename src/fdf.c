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

void print(char *buff)
{
	t_win w;

	w.hi = count_height(buff);
	w.wi = count_width(buff);
	w.x = 0;
	w.y = 0;
	w.jj = 0;
	w.winx = 1600;
	w.winy = 800;
	w.zm = 1;
	w.pr = 1;
	w.z = 1;
	w.table = store(buff);
	w.mlx_ptr = mlx_init();
	w.buff = buff;
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.winx, w.winy, "FDF");
	w.img_ptr = mlx_new_image(w.mlx_ptr, w.winx, w.winy);
	w.img_data = mlx_get_data_addr(w.img_ptr, &w.bpp, &w.size_line, &w.endian);
	mlx_hook(w.win_ptr, 2, 0, keypress, &w);
	drawmap(buff, w.table, &w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img_ptr, 0, 0);
	mlx_loop(w.mlx_ptr);
	free(w.img_data);
	free_tablie(w.table, w.hi);
}
static void rotation(int *x, int *y, int *z, t_win *w)
{
	int previous_x;
	int previous_y;
	int previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	*x = previous_x;
	*y = previous_y * cos(0.45) + previous_z * sin(0.45);
	*z = -previous_y * sin(0.45) + previous_z * cos(0.45);
}

void keypart(int key, t_win *w, int *a)
{
	if (key == 34)
		w->pr = w->pr * -1;
	else if (key == 12)
		w->rx = w->rx * -1;
	else if (key == 7 && w->zm > 1)
		w->zm = w->zm - 1;
	else if (key == 124)
		w->x = w->x + 10;
	else if (key == 125)
		w->y = w->y + 10;
	else if (key == 123)
		w->x = w->x - 10;
	else if (key == 126)
		w->y = w->y - 10;
	else
		*a = 1;
}

int keypress(int key, t_win *w)
{
	int a;

	a = 0;
	if (key == 13)
		w->jj = 1 - w->jj;
	else if (key == 6)
		w->zm = w->zm + 1;
	else if (key == 0)
		w->z = w->z + 1;
	else if (key == 1)
		w->z = w->z - 1;
	else if (key == 53)
		exit(0);
	else
		keypart(key, w, &a);
	if (a == 0)
	{
		ft_bzero(w->img_data, w->winx * w->winy * 4);
		drawmap(w->buff, w->table, w);
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
	}
	return (0);
}

void drawLandD(int i, int j, t_win *w, int **t)
{
	w->x0 = i * w->zm + w->mx;
	w->x1 = (i + w->LR) * w->zm + w->mx;
	w->y0 = j * w->zm + w->my;
	w->y1 = (j + !w->LR) * w->zm + w->my;
	if ((i * w->LR + j * !w->LR) != w->wi * w->LR + w->hi * !w->LR - 1)
	{
		if (w->pr < 0)
		{
			iso(&w->x0, &w->y0, w->table[j][i], w);
			iso(&w->x1, &w->y1, w->table[j + !w->LR][i + w->LR], w);
		}
		line(w, t[j][i] == 0 && t[j + !w->LR][i + w->LR] == 0 ? 0xFFFFFF : 0xFF0000);
	}
}

void drawmap(char *buff, int **t, t_win *w)
{
	int i;
	int j;

	i = 0;
	j = 0;
	w->mx = w->x * (1 - w->jj);
	w->my = w->y * (1 - w->jj);
	while (j < w->hi)
	{
		i = 0;
		while (i < w->wi)
		{
			w->LR = 0;
			drawLandD(i, j, w, t);
			w->LR = 1;
			drawLandD(i, j, w, t);
			i++;
		}
		j++;
	}
}
