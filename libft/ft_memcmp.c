/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:44:36 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/06 12:19:13 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp1;

	temp = (unsigned	char *)s1;
	temp1 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temp[i] < temp1[i])
			return (temp[i] - temp1[i]);
		if (temp[i] > temp1[i])
			return (temp[i] - temp1[i]);
		i++;
	}
	return (0);
}
