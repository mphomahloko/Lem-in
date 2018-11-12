/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:06:51 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 14:15:40 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_farm	farm;
	t_room	*room;
	char	**path;

	room = NULL;
	farm_init(&farm);
	create_farm(&farm, &room);
	veify_farm(&farm, &room);
	path = algo_(&room, &farm);
	send_ants(path, farm.map, farm.n_ants);
	ft_arraydel_s(&path);
	clear_farm(&farm);
	clear_rooms(&room);
	return (0);
}
