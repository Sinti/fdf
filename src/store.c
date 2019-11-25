/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:06:15 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/25 15:34:38 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**store(char *buff)
{
	char	**lines;
	char	**line;
	int		**table;
	t_map	xy;

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

void	free_table(char **table)
{
	int		i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table[i]);
	free(table);
}

void	free_tablie(int **table, int y)
{
	int		i;

	i = 0;
	while (i < y)
	{
		free(table[i]);
		i++;
	}
	free(table[i]);
	free(table);
}
