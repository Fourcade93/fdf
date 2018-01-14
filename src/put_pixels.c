/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 03:30:32 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 06:19:15 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line(t_coord st, t_coord end, int color, t_mlx mlx)
{
	t_draw	draw;

	draw.x1 = st.x;
	draw.x2 = end.x;
	draw.y1 = st.y;
	draw.y2 = end.y;
	draw.dx = ABS((draw.x2 - draw.x1));
	draw.dy = ABS((draw.y2 - draw.y1));
	draw.sx = (draw.x1 < draw.x2) ? 1 : -1;
	draw.sy = (draw.y1 < draw.y2) ? 1 : -1;
	draw.error = draw.dx - draw.dy;
	while (draw.x1 != draw.x2 || draw.y1 != draw.y2)
	{
		mlx_pixel_put(mlx.mlx, mlx.wind, draw.x1, draw.y1, color);
		draw.error2 = draw.error * 2;
		(draw.error2 > -draw.dy) ? draw.error -= draw.dy : draw.error;
		(draw.error2 > -draw.dy) ? draw.x1 += draw.sx : draw.x1;
		(draw.error2 < draw.dx) ? draw.error += draw.dx : draw.error;
		(draw.error2 < draw.dx) ? draw.y1 += draw.sy : draw.y1;
	}
}

int		get_color(int st, int end)
{
	if (!st && !end)
		return (16777215);
	else if (st == end)
		return (7966457);
	else if (st < 0 || end < 0)
		return (2607625);
	return (16711680);
}

void	put_pixels(t_coord **map, int x, t_mlx mlx)
{
	int		i[2];
	int		color;

	i[0] = -1;
	while (map[++(i[0])])
	{
		i[1] = -1;
		while (++(i[1]) < x)
		{
			if (i[1] + 1 < x)
			{
				color = get_color(map[i[0]][i[1]].z, map[i[0]][i[1] + 1].z);
				put_line(map[i[0]][i[1]], map[i[0]][i[1] + 1], color, mlx);
			}
			if (map[i[0] + 1])
			{
				color = get_color(map[i[0]][i[1]].z, map[i[0] + 1][i[1]].z);
				put_line(map[i[0]][i[1]], map[i[0] + 1][i[1]], color, mlx);
			}
		}
	}
}
