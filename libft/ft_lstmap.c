/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:11:42 by mmahloko          #+#    #+#             */
/*   Updated: 2018/06/07 16:07:35 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cursor;
	t_list	*list;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	cursor = f(lst);
	if (!(tmp = ft_lstnew(cursor->content, cursor->content_size)))
		return (NULL);
	list = tmp;
	lst = lst->next;
	while (lst)
	{
		cursor = f(lst);
		if (!(tmp->next = ft_lstnew(cursor->content, cursor->content_size)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (list);
}
