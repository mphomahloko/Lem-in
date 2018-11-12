/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:25:58 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 14:15:27 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_error(t_farm *obj)
{
	ft_putendl_fd("Error", 2);
	clear_farm(obj);
	exit(0);
}

void		ft_error_rm(t_farm *obj, t_room **rooms)
{
	clear_farm(obj);
	clear_rooms(rooms);
	ft_putendl_fd("Error!", 2);
	exit(0);
}

void		ft_error_ad(t_room **rooms, t_farm *obj, t_queue **que)
{
	clear_farm(obj);
	clear_rooms(rooms);
	clear_que(que);
	ft_putendl_fd("Error!", 2);
	exit(0);
}
