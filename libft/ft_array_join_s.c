/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 07:59:31 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 13:22:33 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_join_s(char **arr, char *str)
{
	int		i;
	char	**new;

	i = 0;
	if (!str)
		return (arr);
	if (!arr)
	{
		if (!(new = (char **)malloc(sizeof(char *) * 2)))
			return (NULL);
		new[0] = ft_strdup(str);
		new[1] = NULL;
		return (new);
	}
	while (arr[i])
		i++;
	if (!(new = (char **)malloc(sizeof(char *) * ++i + 2)))
		return (NULL);
	i = -1;
	while (arr[++i])
		new[i] = ft_strdup(arr[i]);
	ft_arraydel_s(&arr);
	new[i++] = ft_strdup(str);
	new[i] = NULL;
	return (new);
}
