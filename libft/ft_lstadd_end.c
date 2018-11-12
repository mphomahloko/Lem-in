/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:20:55 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/13 11:10:16 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *cursor;

	if (!alst || !new)
		return ;
	cursor = (*alst);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
	new->next = NULL;
}
