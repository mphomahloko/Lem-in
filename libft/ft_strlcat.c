/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:16:48 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/13 11:32:43 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	max;

	max = 0;
	i = ft_strlen((const char *)dst);
	j = ft_strlen(src);
	max = i;
	if (i > dstsize)
		max = dstsize;
	max = max + j;
	j = 0;
	if (dstsize > 0)
		while ((i + j) < (dstsize - 1) && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
	dst[i + j] = '\0';
	return (max);
}
