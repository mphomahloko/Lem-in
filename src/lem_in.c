/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:48:00 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 11:18:24 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		queued_rooms(t_queue *queue, char *name)
{
	while (queue)
	{
		if (!ft_strcmp(queue->name, name))
			return (1);
		queue = queue->next;
	}
	return (0);
}

static t_room	*dequeue(t_queue *queue, t_room *room, t_room *rum)
{
	while (ft_strcmp(queue->name, room->name))
		queue = queue->next;
	if (queue->next)
		queue = queue->next;
	else
		return (NULL);
	while (ft_strcmp(queue->name, rum->name))
		rum = rum->next;
	return (rum);
}

static t_queue	*search_graph(t_room *room, t_farm obj)
{
	t_room	*graph;
	t_links	*tmp;
	t_queue	*queue;

	graph = room;
	queue = NULL;
	while (ft_strcmp(graph->name, obj.start))
		graph = graph->next;
	tmp = graph->link;
	add_to_queue(&queue, graph->name, "root");
	while (graph)
	{
		tmp = graph->link;
		while (tmp)
		{
			if (!queued_rooms(queue, tmp->name))
				add_to_queue(&queue, tmp->name, graph->name);
			if (!ft_strcmp(tmp->name, obj.end))
				return (queue);
			tmp = tmp->next;
		}
		graph = dequeue(queue, graph, room);
	}
	return (queue);
}

char			**get_path(t_queue *queue, t_farm obj)
{
	t_queue *tmp;
	t_queue	*tmp1;
	char	**path;

	path = NULL;
	tmp = queue;
	while (tmp->next)
		tmp = tmp->next;
	tmp1 = tmp;
	while (1)
	{
		path = ft_array_join_s(path, tmp->name);
		tmp = queue;
		while (ft_strcmp(tmp->name, tmp1->parent))
			tmp = tmp->next;
		tmp1 = tmp;
		if (!ft_strcmp(obj.start, tmp->name))
			break ;
	}
	path = ft_array_join_s(path, tmp->name);
	return (path);
}

char			**algo_(t_room **room, t_farm *farm)
{
	t_queue	*que;
	t_queue	*tmp;
	char	**path;

	que = search_graph(*room, *farm);
	tmp = que;
	while (tmp->next)
		tmp = tmp->next;
	if (ft_strcmp(tmp->name, farm->end))
		ft_error_ad(room, farm, &que);
	path = get_path(que, *farm);
	clear_que(&que);
	return (path);
}
