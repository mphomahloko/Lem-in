/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 07:39:34 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/06 12:19:03 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	int		dif;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (i > j)
		dif = ft_memcmp(s1, s2, i);
	else
		dif = ft_memcmp(s1, s2, j);
	return (dif);
}
