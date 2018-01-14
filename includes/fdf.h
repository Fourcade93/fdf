/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:30:20 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 06:06:16 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define USAGE "usage: fdf [file name] [chain_width] [height]\n"
# define FILE_ERROR "Incorrect file!\n"
# define ABS(x) ((x < 0) ? -x : x)

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_draw
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
	int			error2;
}				t_draw;

typedef struct	s_mlx
{
	void		*mlx;
	void		*wind;
}				t_mlx;

typedef struct	s_size
{
	int			o_x;
	int			o_z;
}				t_size;

void			error_fnc(t_dlist *list, t_coord **map, int end);
t_coord			**init_map(t_dlist *list, int *x);
void			put_pixels(t_coord **map, int x, t_mlx mlx);
int				exit_x(void *par);
int				event_hook(int key, t_mlx mlx);
void			rotate_map_z(t_coord **map, int x, long double deg);
void			rotate_map_x(t_coord **map, int x, long double deg);
void			shift_fig(t_coord **map, int x);
void			print_pic(t_coord **map, int x);

#endif
