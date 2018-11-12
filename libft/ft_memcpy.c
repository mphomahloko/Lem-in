/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:11:52 by mmahloko          #+#    #+#             */
/*   Updated: 2018/05/30 13:45:33 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*temp;
	char	*temp1;

	temp1 = (char *)dst;
	temp = (char *)src;
	i = 0;
	if (src < dst)
		ft_memmove(dst, src, n);
	else
	{
		while (i < n)
		{
			temp1[i] = temp[i];
			i++;
		}
	}
	return (dst);
}
