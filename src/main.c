/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:08:55 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/12 14:41:54 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

void	call_wind(void)
{
	void	*mlx;
	void	*wind;
	int		x;
	int		y;

	mlx = mlx_init();
	wind = mlx_new_window(mlx, 500, 500, "Hello))");
	y = 99;
	while (++y < 201)
	{
		x = 99;
		while (++x < 201)
			mlx_pixel_put(mlx, wind, x, y, 0xECF90C);
	}
	mlx_loop(mlx);
}

int		check_line(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		while (*str && ft_isdigit(*str))
			str++;
		if (*str && *str != ' ')
			return (0);
		while (*str && *str == ' ')
			str++;
		num++;
	}
	return (num);
}

void	error_fnc(t_dlist *list)
{
	ft_dlstdel(&list, &ft_del_content);
	ft_printf(FILE_ERROR);
	exit(-1);
}

void	valid_input(t_dlist *list)
{
	int		len;
	int		num;
	t_dlist	*tmp;

	if (!list || !(num = check_line(list->data)))
		error_fnc(list);
	len = list->data_size;
	tmp = list;
	while (tmp)
	{
	ft_printf("check\n");
		if (check_line(tmp->data) != num ||
		(int)tmp->data_size != len)
			error_fnc(list);
		tmp = tmp->next;
	}
}

void	fill_sub_arr(int *sub, int x, char *str)
{
	int	i;

	i = -1;
	while (++i < x)
	{
		sub[i] = ft_atoi(str);
		str = ft_strchr(str, ' ');
	}
}

int		**init_map(t_dlist *list, int *x)
{
	int		**map;
	int		y;
	int		i;

	y = ft_dlstlen(list);
	if (!(map = (int**)malloc(sizeof(int*) * (y + 1))))
		return (NULL);
	map[y] = NULL;
	*x = check_line(list->data);
	i = -1;
	while (++i < y)
	{
		if (!(map[i] = (int*)ft_memalloc(*x)))
		{
			i = -1;
			while (map[++i])
				ft_memdel((void**)&(map[i]));
			free(map);
			error_fnc(NULL);
		}
		fill_sub_arr(map[i], *x, list->data);
		list = list->next;
	}
	return (map);
}

int		**read_file(int fd, int *x)
{
	t_dlist	*list;
	char	*line;
	int		**map;
	
	list = NULL;
	while (get_next_line(fd, &line))
	{
		ft_dlst_pushback(&list, ft_dlstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	valid_input(list);
	if (!(map = init_map(list, &(*x))))
		error_fnc(list);
	ft_dlstdel(&list, &ft_del_content);
	return (map);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**map;
	int		x;
	int		i;

	fd = 0;
	if (ac != 2 ||
	(fd = open(av[1], O_RDONLY)) == -1)
	{
		if (fd == -1)
			ft_printf(FILE_ERROR);
		else
			ft_printf(USAGE);
		return (0);
	}
	map = read_file(fd, &x);
	while (*map)
	{
		i = -1;
		while (++i < x)
			ft_printf("%-4d", (*map)[i]);
		ft_printf("\n");
		map++;
	}
	close(fd);
	return (0);
}