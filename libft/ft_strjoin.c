/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:17:32 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/13 11:30:24 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((const char *)s1);
	j = ft_strlen((const char *)s2);
	if (!(s = ft_strnew(i + j)))
		return (NULL);
	s = ft_strcpy(s, s1);
	s = ft_strcat(s, s2);
	return (s);
}
