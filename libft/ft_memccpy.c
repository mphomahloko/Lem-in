/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:07:25 by mmahloko          #+#    #+#             */
/*   Updated: 2018/05/26 15:56:55 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*temp;
	char	*temp1;

	temp1 = (char *)dst;
	temp = (char *)src;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)temp[i] == (unsigned char)c)
		{
			temp1[i] = temp[i];
			i++;
			return (dst + i);
		}
		else
			temp1[i] = temp[i];
		i++;
	}
	return (NULL);
}
