/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:36:29 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/28 15:38:03 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		putimagein(int x, int y, int color, t_win *w)
{
	int i;

	if (x < w->winx && y < w->winy && x > 0 && y > 0)
	{
		i = (x * w->bpp / 8) + (y * w->size_line);
		w->img_data[i] = color + w->v;
		w->img_data[++i] = (color >> 8) + w->v;
		w->img_data[++i] = (color >> 16) + w->v;
		w->img_data[++i] = 0;
	}
}

void			iso(int *x, int *y, int z, t_win *w)
{
	int previous_x;
	int previous_y;

	previous_x = *x - w->x * w->jj;
	previous_y = *y - w->y * w->jj;
	*x = (previous_x - previous_y) * cos(0.52) + w->x * w->jj;
	*y = -(z * w->z) + (previous_x + previous_y) * sin(0.52) + w->y * w->jj;
}

void			brescalc(t_win *w)
{
	w->dx = abs(w->x1 - w->x0);
	w->sx = w->x0 < w->x1 ? 1 : -1;
	w->dy = abs(w->y1 - w->y0);
	w->sy = w->y0 < w->y1 ? 1 : -1;
	w->err = (w->dx > w->dy ? w->dx : -w->dy) / 2;
}

void			line(t_win *w, int cl)
{
	if (!((w->x0 > w->winx && w->x1 > w->winx) || (w->y0 > w->winy && \
	w->y1 > w->winy) || (w->x1 < 0 && w->x0 < 0) || (w->y1 < 0 && w->y0 < 0)))
	{
		brescalc(w);
		while (1)
		{
			putimagein(w->x0, w->y0, cl, w);
			if (w->x0 == w->x1 && w->y0 == w->y1)
				break ;
			w->e2 = w->err;
			if (w->e2 > -w->dx)
			{
				w->err -= w->dy;
				w->x0 += w->sx;
			}
			if (w->e2 < w->dy)
			{
				w->err += w->dx;
				w->y0 += w->sy;
			}
		}
	}
}
