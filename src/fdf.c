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
	w.m = 0;
	w.z = 1;
	w.table = store(buff);
	w.mlx_ptr = mlx_init();
	w.buff = buff;
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.winx + 322, w.winy, "FDF");
	w.img_ptr = mlx_new_image(w.mlx_ptr, w.winx, w.winy);
	w.img_data = mlx_get_data_addr(w.img_ptr, &w.bpp, &w.size_line, &w.endian);
	mlx_hook(w.win_ptr, 2, 0, keypress, &w);
	mlx_hook(w.win_ptr, 4, 0, mouse_press, &w);
	mlx_hook(w.win_ptr, 6, 0, mouse_move, &w);
	drawmap(buff, w.table, &w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img_ptr, 322, 0);
	drawMenu(&w);
	mlx_loop(w.mlx_ptr);
	free(w.img_data);
	free_tablie(w.table, w.hi);
}

void drawrect(t_win *w, int fi, int fj, int cl)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (j < fj)
	{
		i = 0;
		while (i < fi)
		{
			mlx_pixel_put(w->mlx_ptr, w->win_ptr, i, j, cl);
			i++;
		}
		j++;
	}
}

int mouse_press(int b, int x, int y, t_win *w)
{
	if (b == 4)
			w->zm = w->zm + 4;
	if (b == 5 && w->zm > 1)
			w->zm = w->zm - 4;
	if (b == 1)
		w->m = !w->m;
	w->xk = x - 322 - w->x;
	w->yk = y - w->y;
	ft_bzero(w->img_data, w->winx * w->winy * 4);
	drawmap(w->buff, w->table, w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 322, 0);
	return 0;
}

int mouse_move(int x, int y, t_win *w)
{
	if (w->m == 1)
	{
		w->x = x - 322 - w->xk;
		w->y = y - w->yk;
		ft_bzero(w->img_data, w->winx * w->winy * 4);
		drawmap(w->buff, w->table, w);
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 322, 0);
	}
	return 0;
}

void drawMenu(t_win *w)
{
	drawrect(w, 322, 800, 0x4d80e4);
	drawrect(w, 322, 700, 0x5e8ce6);
	drawrect(w, 322, 600, 0x7099e9);
	drawrect(w, 322, 500, 0x82a6ec);
	drawrect(w, 322, 400, 0x94b2ee);
	drawrect(w, 322, 300, 0xa6bff1);
	drawrect(w, 322, 200, 0xb7ccf4);
	drawrect(w, 322, 100, 0x4573CD);
	mlx_string_put(w->mlx_ptr, w->win_ptr, 322 / 2 - 40, 40, 0xFFFFFF, "Fdf Menu");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 20, 140, 0x4d80e4, "Arrow : Move The Map.");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 20, 240, 0x5e8ce6, "Z / X : Zoom In / Out.");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 20, 440, 0x4573CD, "A / S : In / Decrease Z Value.");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 20, 620, 0xa6bff1, "I     : Switch Between");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 20, 640, 0xa6bff1, "        Projections.");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 20, 720, 0xb7ccf4, "W     : Switch Between");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 20, 740, 0xb7ccf4, "        Projections.");
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
		w->m = !w->m;
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
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 322, 0);
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
		w->v = t[j][i] + t[j + !w->LR][i + w->LR];
		line(w, t[j][i] == 0 && t[j + !w->LR][i + w->LR] == 0 ? 0xdff6f0 : 0 + w->z);
	}
}

void drawmap(char *buff, int **t, t_win *w)
{
	int i;
	int j;

	i = 0;
	j = 0;
	w->mx = w->x  - w->wi * w->zm / 2 + 800;
	w->my = w->y  - w->hi * w->zm / 2 + 400;
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
