/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:45:55 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 09:04:06 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_x(void *par)
{
	(void)par;
	exit(1);
	return (0);
}

void	shift_hor(t_coord **map, int x, int n)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
			map[i][j].x += n;
	}
}

void	shift_ver(t_coord **map, int x, int n)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
			map[i][j].y += n;
	}
}

int		event_hook(int key, t_all *all)
{
	if (key == 53)
		exit(1);
	else if (key == 123 || key == 124)
	{
		mlx_clear_window((*all).mlx.mlx, (*all).mlx.wind);
		shift_hor((*all).map, (*all).x, (key == 123) ? -30 : 30);
		put_pixels((*all).map, (*all).x, (*all).mlx);
	}
	else if (key == 126 || key == 125)
	{
		mlx_clear_window((*all).mlx.mlx, (*all).mlx.wind);
		shift_ver((*all).map, (*all).x, (key == 126) ? -30 : 30);
		put_pixels((*all).map, (*all).x, (*all).mlx);
	}
	return (0);
}
