/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:45:55 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/14 05:51:47 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_x(void *par)
{
	(void)par;
	exit(1);
	return (0);
}

int	event_hook(int key, t_mlx mlx)
{
	(void)mlx;
	if (key == 53)
		exit(1);
	return (0);
}
