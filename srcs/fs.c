/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:48:20 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:36:25 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	help_dfs(t_init_cond *cond, t_room **rooms, t_room **a)
{
	t_room	*room_b;
	t_nbors	*nbors;

	while ((*a)->id != cond->end.id || key_table((*a)->name) != cond->end.k)
	{
		nbors = (*a)->nbors;
		while (nbors)
		{
			room_b = find_room_id(rooms, nbors->room.k, nbors->room.id);
			if ((*a)->level + 1 == room_b->level && \
								room_b->from.k == -1 && room_b->from.id == -1)
			{
				room_b->from.id = (*a)->id;
				room_b->from.k = key_table((*a)->name);
				*a = room_b;
				break ;
			}
			nbors = nbors->next;
		}
		if (!nbors && (*a)->from.k >= 0 && (*a)->from.id >= 0)
		{
			(*a)->level = -1;
			*a = find_room_id(rooms, (*a)->from.k, (*a)->from.id);
		}
	}
}

int			dfs(t_init_cond *cond, t_room **rooms)
{
	t_room	*room_a;
	t_room	*room_b;

	set_from(rooms, -1);
	room_a = find_room_id(rooms, cond->start.k, cond->start.id);
	room_a->from.id = 0;
	help_dfs(cond, rooms, &room_a);
	if (room_a->id != cond->end.id || key_table(room_a->name) != cond->end.k)
		return (0);
	while (room_a->id != cond->start.id || \
									key_table(room_a->name) != cond->start.k)
	{
		room_a->path0 = 1;
		room_b = find_room_id(rooms, room_a->from.k, room_a->from.id);
		find_and_rm_nbors(&room_b->nbors, key_table(room_a->name), room_a->id);
		room_a = room_b;
	}
	room_a->path0 = 1;
	set_level(rooms, -1);
	return (1);
}

static int	have_move(t_room **rooms, t_room *room_b)
{
	t_room	*room;
	t_nbors	*nbors;

	nbors = room_b->nbors;
	while (nbors)
	{
		room = find_room_id(rooms, nbors->room.k, nbors->room.id);
		if (find_nbors(room->nbors, key_table(room_b->name), room_b->id) && \
															room->level == -1)
			return (1);
		nbors = nbors->next;
	}
	nbors = room_b->nbors;
	while (nbors)
	{
		room = find_room_id(rooms, nbors->room.k, nbors->room.id);
		if (!find_nbors(room->nbors, key_table(room_b->name), room_b->id))
			return (-1);
		nbors = nbors->next;
	}
	return (0);
}

static int	help_clever_if(t_room **rooms, t_room *room_b)
{
	t_room	*room;
	t_nbors	*nbors;

	nbors = room_b->nbors;
	while (nbors)
	{
		room = find_room_id(rooms, nbors->room.k, nbors->room.id);
		if (!find_nbors(room->nbors, key_table(room_b->name), room_b->id))
		{
			room_b = room;
			return (1);
		}
		nbors = nbors->next;
	}
	return (0);
}

int			clever_if(t_room **rooms, t_room *room_b)
{
	int		c;
	t_room	*room;
	t_nbors	*nbors;

	if (!(c = help_clever_if(rooms, room_b)))
		return (0);
	while ((c = have_move(rooms, room_b)))
	{
		if (c == 1)
			return (1);
		nbors = room_b->nbors;
		while (nbors)
		{
			room = find_room_id(rooms, nbors->room.k, nbors->room.id);
			if (!find_nbors(room->nbors, key_table(room_b->name), room_b->id))
				room_b = room;
			nbors = nbors->next;
		}
	}
	return (0);
}
