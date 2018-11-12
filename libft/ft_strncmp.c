/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 08:09:24 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/13 11:50:05 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp_1;

	temp = (unsigned char *)s1;
	temp_1 = (unsigned char *)s2;
	i = 0;
	while (i < n && (temp[i] || temp_1[i]))
	{
		if (temp[i] < temp_1[i])
			return (temp[i] - temp_1[i]);
		if (temp[i] > temp_1[i])
			return (temp[i] - temp_1[i]);
		i++;
	}
	return (0);
}
