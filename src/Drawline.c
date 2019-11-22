/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 03:56:06 by selibrah          #+#    #+#             */
/*   Updated: 2019/11/20 03:56:08 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void line(int x0, int y0, int x1, int y1, t_win *w, int cl)
{

    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
    int err = (dx>dy ? dx : -dy)/2, e2;

    dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
    err = (dx>dy ? dx : -dy)/2, e2;
    while (1)
    {
        mlx_pixel_put(w->mlx_ptr, w->win_ptr, x0*w->zm, y0*w->zm, cl);
        if (x0 == x1 && y0 == y1)
            break;
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

void drawline(int x0, int y0, int x1, int y1, t_win *w, int cl)
{
    int dx, dy, p;
 
	dx=x1-x0;
	dy=y1-y0;
	p=2*dy-dx;
	while(x0<x1)
	{
        mlx_pixel_put(w->mlx_ptr, w->win_ptr,x0*w->zm, y0*w->zm,cl);
		if(p>=0)
		{
			y0=y0+1;
			p=p+2*dy-2*dx;
		}
		else
			p=p+2*dy;
		x0=x0+1;
	}
}

void drawmap(char *buff, int **table, t_win *w)
{
		int i = 0;
		int j = 0;
		while (j < count_height(buff)){
			i=0;
			while(i < count_width(buff)){
				
				if(i != count_width(buff)-1){
						line(i,j,i+1,j,w,table[j][i] == 0 && table[j][i+1] == 0 ? 0xFFFFFF : 0xFF421A);
				}
				if(j != count_height(buff)-1){
					line(i,j,i,j+1,w,table[j][i] == 0 && table[j+1][i] == 0? 0xFFFFFF : 0xFF421A);
				}
				i++;
			}
				j++;
		}
}*/