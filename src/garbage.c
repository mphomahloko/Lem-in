/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:26:13 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/26 17:08:25 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clear_farm(t_farm *obj)
{
	ft_strdel(&(obj->start));
	ft_strdel(&(obj->end));
	ft_arraydel_s(&(obj->map));
	obj->n_ants = 0;
}

void		clear_rooms(t_room **room)
{
	t_links *tmp1;
	t_links	*tmp2;
	t_room	*tmp;

	while (*room)
	{
		tmp = *room;
		*room = tmp->next;
		tmp1 = tmp->link;
		while (tmp1)
		{
			tmp2 = tmp1;
			tmp1 = tmp2->next;
			ft_strdel(&(tmp2->name));
			tmp2->next = NULL;
			free(tmp2);
			tmp2 = NULL;
		}
		ft_strdel(&(tmp->name));
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void		clear_que(t_queue **que)
{
	t_queue	*tmp;

	while (*que)
	{
		tmp = *que;
		*que = tmp->next;
		ft_strdel(&(tmp->name));
		ft_strdel(&(tmp->parent));
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
}
