/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:31:32 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/05 19:25:12 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*crate_ndata(t_dlist *new, void const *c, size_t c_size)
{
	void	*nc;

	nc = ft_memalloc(c_size);
	if (!nc)
	{
		free(new);
		return (NULL);
	}
	nc = ft_memcpy(nc, c, c_size);
	return (nc);
}

t_dlist		*ft_dlstnew(void const *data, size_t data_size)
{
	t_dlist	*new;
	size_t	nsize;
	void	*ndata;

	new = (t_dlist*)ft_memalloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	if (!data)
	{
		new->data = NULL;
		new->data_size = 0;
	}
	else
	{
		ndata = crate_ndata(new, data, data_size);
		if (!ndata)
			return (NULL);
		nsize = data_size;
		new->data = ndata;
		new->data_size = nsize;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
