/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:37:41 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/04 12:38:53 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_line(char **line, char **res, int fd)
{
	int		count;
	char	*temp;

	count = 0;
	while (res[fd][count] != '\n' && res[fd][count])
		count++;
	if (res[fd][count] == '\n')
	{
		*line = ft_strsub(res[fd], 0, count);
		temp = ft_strdup(res[fd] + count + 1);
		ft_strdel(&res[fd]);
		res[fd] = temp;
		if (res[fd][0] == '\0')
			ft_strdel(&res[fd]);
	}
	else if (res[fd][count] == '\0')
	{
		*line = ft_strdup(res[fd]);
		ft_strdel(&res[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	ssize_t			ret;
	char			buff[BUFF_SIZE + 1];
	static char		*res[0];
	char			*temp;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (res[fd] == NULL)
			res[fd] = ft_strnew(1);
		temp = ft_strjoin(res[fd], buff);
		free(res[fd]);
		res[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (res[fd] == NULL || res[fd][0] == '\0'))
		return (0);
	return (ft_line(line, res, fd));
}
