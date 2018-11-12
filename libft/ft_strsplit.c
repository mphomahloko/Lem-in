/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 06:32:47 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/07 09:48:40 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_numr(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char		*ft_str(char const *s, char c, size_t *x)
{
	unsigned int	start;
	size_t			len;

	while (s[*x])
	{
		len = 0;
		if (s[*x] && s[*x] != c)
		{
			start = *x;
			while (s[*x] && s[*x] != c)
			{
				*x = *x + 1;
				len++;
			}
		}
		if (len > 0)
			return (ft_strsub(s, start, len));
		*x = *x + 1;
	}
	return (ft_strsub(s, start, len));
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	rw;
	char	**str;

	if (!s || !c)
		return (NULL);
	rw = ft_numr(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (rw + 1))))
		return (NULL);
	i = 0;
	x = 0;
	while (i < rw)
	{
		str[i] = ft_str(s, c, &x);
		i++;
	}
	str[rw] = NULL;
	return (str);
}
