/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:38:35 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/25 15:46:08 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define BUFF_SIZE 6000000

typedef struct		s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		x;
	int		x1;
	int		y;
	int		y1;
	int		winx;
	int		winy;
	int		zm;
	char	*buff;
	int		**table;
	int		pr;
	int		z;
	int		z0;
	int		z1;
	int		rx;
	int		mx;
	int		my;
	int		hi;
	int		lx;
	int		wi;
	char	*liner;
	int		li;
	int		lo;
	int		jj;
	int		zmo;
}					t_win;

typedef struct		s_map
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	**lines;
	char	**line;
}					t_map;

int					char_check(char x);
int					check(char *buff);
int					count_height(char *buff);
int					count_width(char *fstline);
int					**store(char *buff);
void				free_table(char **table);
void				free_tablie(int **table, int y);
void				drawmap(char *buff, int **table, t_win *w);
void				print(char *buff);
static void			iso(int *x, int *y, int z, t_win *w);
static void			rotation(int *x, int *y, int *z, t_win *w);
int					keypress(int key, t_win *w);
void				line(int x0, int y0, int x1, int y1,\
		t_win *w, int cl, int **table, int wi);
#endif
