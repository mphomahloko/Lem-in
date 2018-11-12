/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 08:28:03 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/06 16:08:58 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *ndle)
{
	size_t i;
	size_t j;

	i = 0;
	if (ndle[0] == '\0')
		return ((char *)hay);
	while (hay[i])
	{
		j = 0;
		while ((char)hay[i + j] == (char)ndle[j])
		{
			if ((char)ndle[j + 1] == '\0')
				return ((char *)hay + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
