/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:19:10 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/29 12:24:25 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"

typedef struct		s_queue
{
	char			*name;
	char			*parent;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_links
{
	char			*name;
	struct s_links	*next;
}					t_links;

typedef struct		s_room
{
	char			*name;
	struct s_room	*next;
	struct s_links	*link;
}					t_room;

typedef struct		s_farm
{
	int				n_ants;
	char			**map;
	char			*start;
	char			*end;
}					t_farm;

int					verify_int(char *str);
void				farm_init(t_farm *farm);
void				clear_farm(t_farm *obj);
void				ft_error(t_farm *obj);
void				clear_que(t_queue **que);
void				clear_rooms(t_room **room);
char				**algo_(t_room **room, t_farm *farm);
int					add_link(char *lnk_str, t_room **room);
void				veify_farm(t_farm *farm, t_room **room);
void				create_farm(t_farm *obj, t_room **room);
void				ft_error_rm(t_farm *obj, t_room **rooms);
void				send_ants(char	**path, char **map, int n_ants);
int					veri_link(t_farm *obj, t_room **room, int index);
int					veri_room(t_farm *obj, t_room **room, int index);
int					ft_duplicate_room(t_room *rooms, char *new_room);
void				add_room(t_farm *obj, t_room **room, int *stat, int i);
void				ft_error_ad(t_room **room, t_farm *farm, t_queue **que);
void				add_to_queue(t_queue **queue, char *child, char *parent);

#endif
