#include "fdf.h"

void free_table(char **table)
{
	int i;
	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table[i]);
	free(table);
}

void free_tablie(int **table, int y)
{
	int i;
	i = 0;
	while (i < y)
	{
		free(table[i]);
		i++;
	}
	free(table[i]);
	free(table);
}

int check(char *buff)
{
	t_map xy;
	char **lines;
	char **line;

	xy.i = 0;
	while (buff[xy.i])
	{
		if (ft_isalnum(buff[xy.i]) == 0 && buff[xy.i] != ' ' && buff[xy.i] != ',' && buff[xy.i] != '\n' && buff[xy.i] != '-')
			return (0);
		xy.i++;
	}
	xy.x = count_width(buff);
	lines = ft_strsplit(buff, '\n');
	xy.i = 0;
	while (lines[xy.i])
	{

		line = ft_strsplit(lines[xy.i], ' ');
		xy.j = 0;
		while (line[xy.j])
			xy.j++;
		free_table(line);
		if ((xy.j) < xy.x)
			return (0);
		xy.i++;
	}
	free_table(lines);

	return (1);
}
static void iso(int *x, int *y, int z, t_win *w)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.52) + w->x * w->jj;
	*y = -(z * w->z) + (previous_x + previous_y) * sin(0.52) + w->y * w->jj;
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

int count_height(char *buff)
{

	int i;
	char **lines;

	i = 0;
	lines = ft_strsplit(buff, '\n');
	while (lines[i])
		i++;
	free_table(lines);
	return (i);
}

int count_width(char *buff)
{
	int i;
	char **lines;
	char **fstline;

	i = 0;
	lines = ft_strsplit(buff, '\n');
	fstline = ft_strsplit(lines[0], ' ');
	while (fstline[i])
		i++;
	free_table(lines);
	free_table(fstline);
	return (i);
}

int **store(char *buff)
{
	char **lines;
	char **line;
	int **table;
	t_map xy;

	xy.i = 0;
	xy.x = count_width(buff);
	xy.y = count_height(buff);
	lines = ft_strsplit(buff, '\n');
	table = (int **)malloc(xy.y * sizeof(int *));
	while (lines[xy.i])
	{
		line = ft_strsplit(lines[xy.i], ' ');
		xy.j = 0;
		table[xy.i] = (int *)malloc(xy.x * sizeof(int));
		while (xy.j < xy.x)
		{
			table[xy.i][xy.j] = ft_atoi(line[xy.j]);
			xy.j++;
		}
		xy.i++;
		free_table(line);
	}
	free_table(lines);
	return (table);
}

void line(int x0, int y0, int x1, int y1, t_win *w, int cl, int **table, int wi)
{

	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	
	if (w->pr < 0)
	{
		iso(&x0, &y0, table[(y0 - w->my) / wi][(x0 - w->mx) / wi], w);
		iso(&x1, &y1, table[(y1 - w->my) / wi][(x1 - w->mx) / wi], w);
	}
	//x0 = (w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500 + x0)%(w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500);
	//y0 = ((w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500) + y0)%(w->hi * (w->zm > w->zmo ? w->zm : w->zmo) + 500);
	//x1 = (w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500 + x1)%(w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500);
	//y1 = ((w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500) + y1)%(w->hi * (w->zm > w->zmo ? w->zm : w->zmo) + 500);
	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{   
		//mlx_pixel_put(w->mlx_ptr, w->win_ptr,x0 ,y0 , cl);
		//mlx_pixel_put(w->mlx_ptr, w->win_ptr,(w->winx + x0)%(w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500) ,(w->winy + y0)%(w->hi * (w->zm > w->zmo ? w->zm : w->zmo) + 500) , cl);
	mlx_pixel_put(w->mlx_ptr, w->win_ptr, (x0 > w->winx ? x0 % (w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500) \
		: (x0 < 0 ? w->wi * (w->zm > w->zmo ? w->zm : w->zmo) + 500 + x0 % (-w->wi * \
		(w->zm > w->zmo ?\
		 w->zm : w->zmo) - 500) : x0)),\
		(y0 > w->winy ? y0 % (w->hi * (w->zm > w->zmo ? w->zm : w->zmo) + 500) : \
		(y0 < 0 ? w->hi * (w->zm > w->zmo ? w->zm : w->zmo) + 500 + y0 % (-w->hi * \
		(w->zm > w->zmo ? w->zm : w->zmo) - 500) : y0)), cl);
		//printf("x0 = %d |||| y0 = %d \n",x0,y0);
		if (x0 == x1 && y0 == y1 )
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

void drawmap(char *buff, int **table, t_win *w)
{ 
	int i = 0;
	int j = 0;
	w->mx = w->x * (1 - w->jj);// - w->wi * w->zm / 2 + (w->winx) / 2;
	w->my = w->y * (1 - w->jj) ;//- w->hi * w->zm / 2 + (w->winy) / 2;
	
	while (j < w->hi)
	{
		i = 0;
		while (i < w->wi)
		{

			if (i != w->wi - 1)
			{
				line((i)*w->zm + w->mx, j * w->zm + w->my, (i + 1) * w->zm + w->mx, j * w->zm + w->my, w, table[j][i] == 0 && table[j][i + 1] == 0 ? 0xFFFFFF : 0xFF00FF, table, w->zm);
			}
			if (j != w->hi - 1)
			{
				line(i * w->zm + w->mx, j * w->zm + w->my, i * w->zm + w->mx, (j + 1) * w->zm + w->my, w, table[j][i] == 0 && table[j + 1][i] == 0 ? 0xFFFFFF : 0xFF00FF, table, w->zm);
			}
			i++;
		}
		j++;
	}
}

int keypress(int key, t_win *w)
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

void print(char *buff)
{
	t_win w;
	int bp;
	int sl;
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
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.winx, w.winy, "hi Motherfucker");
	w.img_ptr = mlx_new_image(w.mlx_ptr,500,500);
	
	w.winx = 500 + w.wi * w.zm;
	w.winy = 500 + w.hi * w.zm;
	mlx_hook(w.win_ptr, 2, 0, keypress, &w);
	drawmap(buff, w.table, &w);
	ft_putstr("finish\n");
	//free_tablie(w.table, w.hi);
	mlx_loop(w.mlx_ptr);
}
