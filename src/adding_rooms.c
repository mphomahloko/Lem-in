/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:30:17 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 13:32:32 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	name_room(t_room *n_room, int *stat, t_farm *obj, t_room **room)
{
	if (*stat == 1)
		obj->start = ft_strdup(n_room->name);
	else if (*stat == 2)
		obj->end = ft_strdup(n_room->name);
	if (obj->end && obj->start)
		if (!ft_strcmp(obj->end, obj->start))
			ft_error_rm(obj, room);
	*stat = 0;
}

static	int	new_link(t_room **n_lnk, char *name_link)
{
	t_links	*new;
	t_links *tmp;

	new = (t_links*)malloc(sizeof(t_links));
	new->next = NULL;
	new->name = ft_strdup(name_link);
	if (!((*n_lnk)->link))
		(*n_lnk)->link = new;
	else
	{
		tmp = (*n_lnk)->link;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int			add_link(char *lnk_str, t_room **room)
{
	char	**link_;
	t_room	*tmp;
	t_room	*tmp1;

	tmp = *room;
	tmp1 = *room;
	link_ = ft_strsplit(lnk_str, '-');
	while (tmp && ft_strcmp(tmp->name, link_[0]))
		tmp = tmp->next;
	while (tmp1 && ft_strcmp(tmp1->name, link_[1]))
		tmp1 = tmp1->next;
	if (!new_link(&tmp, link_[1]) || !new_link(&tmp1, link_[0]))
	{
		ft_arraydel_s(&link_);
		return (0);
	}
	ft_arraydel_s(&link_);
	return (1);
}

void		add_room(t_farm *obj, t_room **room, int *stat, int i)
{
	t_room	*new;
	t_room	*tmp;

	tmp = *room;
	if (!veri_room(obj, room, i))
		return ;
	if (ft_duplicate_room(tmp, obj->map[i]))
		ft_error_rm(obj, room);
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		ft_error_rm(obj, room);
	new->name = ft_strndup(obj->map[i]\
			, ft_strchr(obj->map[i], ' ') - obj->map[i]);
	new->next = NULL;
	new->link = NULL;
	name_room(new, stat, obj, room);
	if (!tmp)
	{
		*room = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		add_to_queue(t_queue **queue, char *child, char *parent)
{
	t_queue	*new;
	t_queue	*tmp;

	if (!child)
		return ;
	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		return ;
	new->name = ft_strdup(child);
	new->parent = ft_strdup(parent);
	new->next = NULL;
	tmp = *queue;
	if (!tmp)
	{
		*queue = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
