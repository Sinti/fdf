/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:36:29 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/25 15:38:27 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		iso(int *x, int *y, int z, t_win *w)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.52) + w->x * w->jj;
	*y = -(z * w->z) + (previous_x + previous_y) * sin(0.52) + w->y * w->jj;
}

void			line(int x0, int y0, int x1, int y1, t_win *w, int cl, int **table, int wi)
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;

	if (w->pr < 0)
	{
		iso(&x0, &y0, table[(y0 - w->my) / wi][(x0 - w->mx) / wi], w);
		iso(&x1, &y1, table[(y1 - w->my) / wi][(x1 - w->mx) / wi], w);
	}
	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, (x0 > w->winx ? x0 % (w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500)\
		: (x0 < 0 ? w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500 + x0 % (-w->wi *\
		(w->zm > w->zmo ?\
		 w->zm : w->zmo) - 500) : x0)),\
		(y0 > w->winy ? y0 % (w->hi * (w->zm > w->zmo ? w->zm : w->zmo) + 500) :\
		(y0 < 0 ? w->hi * (w->zm > w->zmo ? w->zm : w->zmo) + 500 + y0 % (-w->hi *\
		(w->zm > w->zmo ? w->zm : w->zmo) - 500) : y0)), cl);
		if (x0 == x1 && y0 == y1 )
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
