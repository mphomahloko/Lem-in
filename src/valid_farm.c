/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_farm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 00:18:28 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 13:22:41 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			farm_init(t_farm *farm)
{
	farm->start = NULL;
	farm->end = NULL;
	farm->map = NULL;
	farm->n_ants = 0;
}

void			send_ants(char **path, char **map, int n_ants)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (map[++i])
		ft_putendl(map[i]);
	ft_putchar('\n');
	while (++j <= n_ants)
	{
		i = 0;
		while (path[i])
			i++;
		i--;
		while (i > 0)
		{
			ft_putchar('L');
			ft_putnbr(j);
			ft_putchar('-');
			ft_putendl(path[--i]);
		}
	}
}

static int		farm_linked(t_room *room, char *name)
{
	t_links	*tmp;

	while (room)
	{
		tmp = room->link;
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, name))
				return (1);
			tmp = tmp->next;
		}
		room = room->next;
	}
	return (0);
}

int				ft_duplicate_room(t_room *rooms, char *new_room)
{
	char	**dup;

	dup = ft_strsplit(new_room, ' ');
	while (rooms && ft_strcmp(rooms->name, dup[0]))
		rooms = rooms->next;
	ft_arraydel_s(&dup);
	if (!rooms)
		return (0);
	return (1);
}

void			veify_farm(t_farm *farm, t_room **room)
{
	if (!farm->start || !farm->end)
		ft_error_rm(farm, room);
	if (!farm_linked(*room, farm->start) || !farm_linked(*room, farm->end))
		ft_error_rm(farm, room);
}
