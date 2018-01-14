/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:08:55 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 06:35:36 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_size(t_size *size, t_coord **map, int x, char **av)
{
	int	i;
	int	j;
	int	max_z;

	if (av)
	{
		(*size).o_x = (ft_atoi(av[2]) > 100) ? 100 : ft_atoi(av[2]);
		(*size).o_z = (ft_atoi(av[3]) > 50) ? 50 : ft_atoi(av[3]);
		return ;
	}
	i = -1;
	max_z = 0;
	(*size).o_z = 20;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
			if (ABS(map[i][j].z) > max_z)
				max_z = map[i][j].z;
	}
	if (x > 40 || i > 30)
		(*size).o_x = 1500 / x;
	else
		(*size).o_x = 40;
	(max_z > 20) ? (*size).o_z = 2 : (*size).o_z;
}

void	init_map_size(t_coord **map, int x, char **av, int ac)
{
	t_size	size;
	int		i;
	int		j;

	if (ac > 3)
		init_size(&size, map, x, av);
	else
		init_size(&size, map, x, NULL);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < x)
		{
			map[i][j].x *= size.o_x;
			map[i][j].y *= size.o_x;
			map[i][j].z *= size.o_z;
		}
	}
}

t_coord	**read_file(int fd, int *x)
{
	t_dlist	*list;
	char	*line;
	t_coord	**map;

	list = NULL;
	while (get_next_line(fd, &line))
	{
		ft_dlst_pushback(&list, ft_dlstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	if (!(map = init_map(list, &(*x))))
		error_fnc(list, NULL, 0);
	ft_dlstdel(&list, &ft_del_content);
	return (map);
}

int		main(int ac, char **av)
{
	int		fd;
	t_coord	**map;
	int		x;

	fd = 0;
	if (ac == 1 || ac > 4 || (fd = open(av[1], O_RDONLY)) == -1)
	{
		if (fd == -1)
			ft_printf(FILE_ERROR);
		else
			ft_printf(USAGE);
		return (0);
	}
	map = read_file(fd, &x);
	init_map_size(map, x, av, ac);
	rotate_map_z(map, x, -0.5235987755983);
	rotate_map_x(map, x, -1.0472);
	shift_fig(map, x);
	print_pic(map, x);
	close(fd);
	return (0);
}
