/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:07:44 by mmahloko          #+#    #+#             */
/*   Updated: 2018/05/25 12:40:35 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t len)
{
	char *temp;
	char *temp1;

	temp = (char *)s1;
	temp1 = (char *)s2;
	if (temp1 < temp)
	{
		while ((int)--len >= 0)
			temp[len] = temp1[len];
	}
	else
		ft_memcpy(s1, s2, len);
	return (s1);
}
