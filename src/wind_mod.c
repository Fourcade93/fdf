/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wind_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:48:40 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 09:04:01 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_win_size(int *width, int *height, t_coord **map, int x)
{
	int	max_y;
	int	max_x;
	int	i;
	int	j;

	max_y = 100;
	max_x = 100;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
		{
			if (map[i][j].x > max_x)
				max_x = map[i][j].x;
			if (map[i][j].y > max_y)
				max_y = map[i][j].y;
		}
	}
	*width = max_x + 100;
	*height = max_y + 100;
}

t_mlx	call_wind(int width, int height)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.wind = mlx_new_window(mlx.mlx, width, height, "fmallaba-fdf");
	return (mlx);
}

void	print_pic(t_coord **map, int x)
{
	t_mlx	mlx;
	int		width;
	int		height;
	t_all	all;

	all.map = map;
	all.x = x;
	get_win_size(&width, &height, map, x);
	mlx = call_wind(width, height);
	all.mlx = mlx;
	put_pixels(map, x, mlx);
	mlx_key_hook(mlx.wind, event_hook, &all);
	mlx_hook(mlx.wind, 17, 1L << 17, exit_x, NULL);
	mlx_loop(mlx.mlx);
}
