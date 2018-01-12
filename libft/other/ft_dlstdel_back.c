/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 20:39:10 by fmallaba          #+#    #+#             */
/*   Updated: 2018/01/05 17:19:32 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel_back(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;

	if (!alst)
		return ;
	if (!((*alst)->next))
	{
		ft_dlstdelone(&(*alst), del);
		return ;
	}
	tmp = *alst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp = tmp->prev;
	ft_dlstdelone(&(tmp->next), del);
}
