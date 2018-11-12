/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:31:58 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 14:15:12 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		cread_ants(t_farm *obj)
{
	char	*line;
	int		i;

	i = 1;
	while (get_next_line(0, &line) > 0)
	{
		obj->map = ft_array_join_s(obj->map, line);
		ft_strdel(&line);
		if (!ft_strcmp("##start", obj->map[i]) ||\
				!ft_strcmp("##end", obj->map[i]) || obj->map[i][0] != '#')
			break ;
		i++;
	}
	return (i);
}

static int		read_ants(t_farm *obj)
{
	char	*line;
	int		i;

	i = 0;
	obj->map = (char **)malloc(sizeof(char *) * 2);
	if (get_next_line(0, &line) != 1)
	{
		ft_putendl("Error!");
		exit(0);
	}
	obj->map[0] = ft_strdup(line);
	obj->map[1] = NULL;
	ft_strdel(&line);
	if (!ft_isdigit(obj->map[0][0]) && obj->map[0][0] == '#')
		if (ft_strcmp("##start", obj->map[0]) &&\
				ft_strcmp("##end", obj->map[0]))
			i = cread_ants(obj);
	if (!verify_int(obj->map[i]) || ft_atoi(obj->map[i]) < 1)
		ft_error(obj);
	obj->n_ants = ft_atoi(obj->map[i]);
	return (i);
}

static int		read_rooms(t_farm *obj, t_room **room, int i)
{
	char	*line;
	int		status;

	status = 0;
	while (get_next_line(0, &line) > 0 && ++i)
	{
		obj->map = ft_array_join_s(obj->map, line);
		ft_strdel(&line);
		if ((!ft_strcmp(&obj->map[i][0], "#") &&\
					!ft_strchr(obj->map[i], ' ')) ||\
				ft_strchr(obj->map[i], '-'))
			break ;
		if (!ft_strcmp("##start", obj->map[i]) ||\
				!ft_strcmp("##end", obj->map[i]))
		{
			if (!obj->start && !status && !ft_strcmp("##start", obj->map[i]))
				status = 1;
			else if (!obj->end && !status && !ft_strcmp("##end", obj->map[i]))
				status = 2;
			else
				ft_error_rm(obj, room);
		}
		add_room(obj, room, &status, i);
	}
	return (i);
}

static void		read_links(t_farm *obj, t_room **room, int i)
{
	char	*line;

	while (1)
	{
		if (veri_link(obj, room, i))
		{
			if (!add_link(obj->map[i], room))
				ft_error_rm(obj, room);
		}
		else if (!ft_strcmp(obj->map[i], "##start") ||\
				!ft_strcmp(obj->map[i], "##end"))
			ft_error_rm(obj, room);
		if (get_next_line(0, &line) != 1)
			break ;
		obj->map = ft_array_join_s(obj->map, line);
		ft_strdel(&line);
		i++;
	}
}

void			create_farm(t_farm *obj, t_room **room)
{
	int		i;

	i = 0;
	i = read_ants(obj);
	i = read_rooms(obj, room, i);
	read_links(obj, room, i);
}
