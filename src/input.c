/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:50:11 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 12:17:17 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_char(char *str, char c)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == c)
			count++;
	return (count);
}

static int	ft_similar(char **map, char *room)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (count_char(map[i], ' ') == 2)
			if (ft_strstr(map[i], ft_strchr(room, ' ')))
				j++;
		i++;
	}
	if (j >= 2)
		return (1);
	return (0);
}

int			verify_int(char *str)
{
	int		i;
	long	nbr;

	i = -1;
	nbr = ft_atol(str);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (0);
	return (1);
}

int			veri_room(t_farm *obj, t_room **room, int index)
{
	char	**isroom;
	int		i;

	i = 0;
	isroom = NULL;
	if (obj->map[index][0] == '#')
		return (0);
	else if (obj->map[index][0] == '\0')
		ft_error_rm(obj, room);
	isroom = ft_strsplit(obj->map[index], ' ');
	while (isroom[++i])
		if (!verify_int(isroom[i]) || count_char(obj->map[index], ' ') != 2)
		{
			ft_arraydel_s(&isroom);
			ft_error_rm(obj, room);
		}
	if (i != 3 || isroom[0][0] == 'L' || isroom[0][0] == '-' ||\
			ft_similar(obj->map, obj->map[index]))
	{
		ft_arraydel_s(&isroom);
		ft_error_rm(obj, room);
	}
	ft_arraydel_s(&isroom);
	return (1);
}

int			veri_link(t_farm *obj, t_room **room, int index)
{
	int		i;
	char	**link;
	t_room	*valid;

	i = 0;
	valid = *room;
	if (obj->map[index][0] == '#')
		return (0);
	link = ft_strsplit(obj->map[index], '-');
	while (link[i])
		i++;
	if (i != 2 || count_char(obj->map[index], '-') != 1)
		ft_error_rm(obj, room);
	i = 0;
	while (valid && (i < 2) && ft_strcmp(link[0], link[1]))
	{
		if (!ft_strcmp(valid->name, link[0]) ||\
				!ft_strcmp(valid->name, link[1]))
			i++;
		valid = valid->next;
	}
	if (i != 2)
		ft_error_rm(obj, room);
	ft_arraydel_s(&link);
	return (1);
}
