/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:42:56 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/17 18:45:33 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*buf;

	if (alst != NULL && del != NULL)
		if ((*alst))
			while ((*alst))
			{
				buf = (*alst);
				(*alst) = (*alst)->next;
				del(buf->data, buf->data_size);
				free(buf);
				buf = NULL;
			}
}
