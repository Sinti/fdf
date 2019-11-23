/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:38:35 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/15 13:07:57 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define BUFF_SIZE 6000000
typedef struct 		s_win
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int x;
    int y;
    int winx;
    int winy;
    int zm;
    char *buff;
    int **table;
    int pr;
    int z;
    int z0;
    int z1;
    int rx;
    int mx;
    int my;
    int hi;
    int lx;
    int wi;
    char *liner;
    int		li;
	int		lo;
    int jj;
    int zmo;
} 					t_win;
typedef struct		s_map
{
	int		x;
	int		y;
	int		i;
	int		j;
}					t_map;

int					check(char *buff);
int					count_height(char *buff);
int					count_width(char *fstline);
int					**store(char *buff);
void				print(char *buff);
#endif
