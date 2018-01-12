/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:47:22 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/22 11:57:34 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	t_dlist	*head;

	if (alst != NULL && new != NULL)
	{
		head = (*alst);
		new->next = head;
		if (head)
			head->prev = new;
		(*alst) = new;
	}
}
