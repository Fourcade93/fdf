/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fnc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 02:29:04 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 05:47:09 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_fnc(t_dlist *list, t_coord **map, int end)
{
	int		i;

	ft_dlstdel(&list, &ft_del_content);
	if (map)
	{
		i = -1;
		while (++i < end)
			ft_memdel((void**)&(map[i]));
		free(map);
	}
	ft_printf(FILE_ERROR);
	exit(-1);
}
