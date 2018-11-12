/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:11:21 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/06 16:07:47 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (ndle[0] == '\0')
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while ((char)hay[i + j] == (char)ndle[j] && (i + j) < len)
		{
			if (ndle[j + 1] == '\0')
				return ((char *)hay + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
