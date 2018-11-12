/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 10:49:41 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/14 12:07:33 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstcount(t_list *alst)
{
	size_t	i;

	if (!alst)
		return (0);
	i = 0;
	while (alst)
	{
		i++;
		alst = alst->next;
	}
	return (i);
}
