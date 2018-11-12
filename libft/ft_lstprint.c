/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 10:52:18 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/13 11:15:42 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **alst)
{
	t_list *cursor;

	if (!alst)
		return ;
	cursor = (*alst);
	while (cursor)
	{
		ft_putendl(cursor->content);
		cursor = cursor->next;
	}
}
