/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:06:04 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/28 16:22:57 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init(t_win *w, char *buff)
{
	w->hi = count_height(buff);
	w->wi = count_width(buff);
	w->x = 0;
	w->y = 0;
	w->jj = 0;
	w->winx = 1600;
	w->winy = 800;
	w->zm = w->hi * w->wi * 20 < 1600 * 800 ? 20 : 1;
	w->pr = 1;
	w->cl = 0;
	w->m = 0;
	w->z = 1;
}

void		mlx_start(char *buff)
{
	t_win	w;

	init(&w, buff);
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
	drawmenu(&w);
	mlx_loop(w.mlx_ptr);
	free(w.img_data);
	free_tablie(w.table, w.hi);
}

void		drawlandd(int i, int j, t_win *w, int **t)
{
	w->x0 = i * w->zm + w->mx;
	w->x1 = (i + w->lr) * w->zm + w->mx;
	w->y0 = j * w->zm + w->my;
	w->y1 = (j + !w->lr) * w->zm + w->my;
	if ((i * w->lr + j * !w->lr) != w->wi * w->lr + w->hi * !w->lr - 1)
	{
		if (w->pr < 0)
		{
			iso(&w->x0, &w->y0, w->table[j][i], w);
			iso(&w->x1, &w->y1, w->table[j + !w->lr][i + w->lr], w);
		}
		w->v = t[j][i] + t[j + !w->lr][i + w->lr];
		line(w, t[j][i] == 0 && t[j + !w->lr][i + w->lr] == 0\
				? 0xdff6f0 : (0 + w->cl)  + !w->cl * 0xE51635);
	}
}

void		drawmap(char *buff, int **t, t_win *w)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	w->mx = w->x - w->wi * w->zm / 2 + 800;
	w->my = w->y - w->hi * w->zm / 2 + 400;
	while (j < w->hi)
	{
		i = 0;
		while (i < w->wi)
		{
			w->lr = 0;
			drawlandd(i, j, w, t);
			w->lr = 1;
			drawlandd(i, j, w, t);
			i++;
		}
		j++;
	}
}

void		drawrect(t_win *w, int fi, int fj, int cl)
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
