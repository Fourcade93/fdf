/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:47:07 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 08:36:00 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_map_z(t_coord **map, int x, long double deg)
{
	int	i;
	int	j;
	int	len;

	len = -1;
	while (map[++len])
		;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
		{
			len = map[i][j].x;
			map[i][j].x = len * cos(deg) + map[i][j].y * sin(deg);
			map[i][j].y = map[i][j].y * cos(deg) - len * sin(deg);
		}
	}
}

void	rotate_map_x(t_coord **map, int x, long double deg)
{
	int	i;
	int	j;
	int	len;

	len = -1;
	while (map[++len])
		;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
		{
			len = map[i][j].z;
			map[i][j].y = map[i][j].y * cos(deg) + map[i][j].z * sin(deg);
			map[i][j].z = map[i][j].z * cos(deg) - len * sin(deg);
		}
	}
}

void	shift_fig_help(t_coord **map, int x, int min_y, int min_x)
{
	int	i;
	int	j;

	(min_y < 0) ? min_y = ABS(min_y) + 50 : min_y;
	(min_x < 0) ? min_x = ABS(min_x) + 50 : min_x;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
		{
			map[i][j].y += min_y;
			map[i][j].x += min_x;
		}
	}
}

void	shift_fig(t_coord **map, int x)
{
	int	min_y;
	int	min_x;
	int	i;
	int	j;

	i = -1;
	min_y = 0;
	min_x = 0;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
		{
			if (map[i][j].y < min_y)
				min_y = map[i][j].y;
			if (map[i][j].x < min_x)
				min_x = map[i][j].x;
		}
	}
	if (min_y < 0 || min_x < 0)
		shift_fig_help(map, x, min_y, min_x);
}
