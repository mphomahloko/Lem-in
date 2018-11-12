/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:09:26 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/07 11:35:10 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_range(int nbr)
{
	char	*str;
	int		num_len;
	int		i;

	i = 0;
	num_len = ft_numlen(nbr);
	if (!(str = ft_strnew((size_t)num_len)))
		return (NULL);
	if (nbr >= -2147483647 && nbr < 0)
	{
		str[i++] = '-';
		nbr = -nbr;
	}
	while (i <= --num_len)
	{
		str[num_len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*min_int;
	char	*str;

	min_int = "-2147483648";
	if (n == -2147483648)
		str = ft_strdup(min_int);
	else
		str = ft_itoa_range(n);
	return (str);
}
