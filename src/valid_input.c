/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 01:58:24 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 05:52:29 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fill_sub_arr(t_coord *sub, int x, int y, char **str)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < x)
	{
		tmp = *str;
		while (*tmp && !ft_isdigit(*tmp))
			tmp++;
		if (!*tmp)
			return (0);
		sub[i].z = ft_atoi(tmp);
		sub[i].y = y;
		sub[i].x = i;
		str++;
	}
	return (1);
}

void	del_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		ft_strdel(&(arr[i]));
	free(arr);
}

int		arr_len(char **arr)
{
	int len;

	if (!arr)
		return (0);
	len = -1;
	while (arr[++len])
		;
	return (len);
}

void	init_map_help(t_dlist *list, int x, t_coord **map, int y)
{
	int		i;
	char	**arr;
	t_dlist *tmp;

	i = -1;
	tmp = list;
	while (++i < y)
	{
		if (!(map[i] = (t_coord*)ft_memalloc(sizeof(t_coord) * x)))
			error_fnc(list, map, i);
		arr = ft_strsplit(tmp->data, ' ');
		if (arr_len(arr) != x || !fill_sub_arr(map[i], x, i, arr))
			error_fnc(list, map, i);
		del_arr(arr);
		tmp = tmp->next;
	}
}

t_coord	**init_map(t_dlist *list, int *x)
{
	t_coord	**map;
	char	**arr;
	int		y;

	y = ft_dlstlen(list);
	if (!(map = (t_coord**)malloc(sizeof(t_coord*) * (y + 1))))
		return (NULL);
	map[y] = NULL;
	arr = ft_strsplit(list->data, ' ');
	if (!(*x = arr_len(arr)))
		error_fnc(list, map, 0);
	del_arr(arr);
	init_map_help(list, *x, map, y);
	return (map);
}
