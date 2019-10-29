/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:37:54 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:40:28 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_tables(t_init_cond **cond, t_room ***room)
{
	size_t	i;

	if (!(*room = (t_room **)malloc(sizeof(t_room *) * SIZE_OF_TABLE)))
		ft_exit((*cond)->fd, NULL, -2);
	if (!(*cond = (t_init_cond *)malloc(sizeof(t_init_cond))))
		ft_exit((*cond)->fd, NULL, -2);
	i = 0;
	while (i++ != SIZE_OF_TABLE)
		*(*room + i) = NULL;
	(*cond)->fd = 0;
	(*cond)->flag = 0;
	(*cond)->ants = -1;
	(*cond)->start.k = -1;
	(*cond)->start.id = -1;
	(*cond)->end.k = -1;
	(*cond)->end.id = -1;
}

void	init_ant_and_path(t_init_cond *cond, t_room **rooms, \
												t_ant **ant, t_path **path)
{
	int		i;
	t_room	*room;
	t_nbors	*nbors;

	*ant = NULL;
	*path = NULL;
	length(cond, rooms, 1);
	nbors = (find_room_id(rooms, cond->start.k, cond->start.id))->nbors;
	while (nbors)
	{
		room = find_room_id(rooms, nbors->room.k, nbors->room.id);
		ft_add_path(path, ft_path_new(room->level, nbors->room, 0, cond->fd));
		nbors = nbors->next;
	}
	i = cond->ants;
	while (i)
	{
		ft_add_ant(ant, ft_ant_new(i, NULL, cond->fd));
		i--;
	}
}
