/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:36:59 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/09 10:33:19 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_split(char const *s, char c)
{
	t_list	*list;
	t_list	*cursor;
	char	**str;
	int		i;

	str = ft_strsplit(s, c);
	if (!(list = ft_lstnew(str[0], ft_strlen(str[0]) + 1)))
		return (NULL);
	i = 1;
	while (str[i])
	{
		if (!(cursor = ft_lstnew(str[i], ft_strlen(str[i]) + 1)))
			return (NULL);
		ft_lstadd_end(&list, cursor);
		i++;
	}
	while (cursor)
		cursor = cursor->next;
	while (i >= 0)
		ft_strdel(&str[i--]);
	free(str);
	return (list);
}
