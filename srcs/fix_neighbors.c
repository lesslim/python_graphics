/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_neighbors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 04:40:02 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 23:00:00 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_unused(t_room **rooms, t_room *room)
{
	t_room	*tmp;
	t_nbors	*nbors;

	nbors = room->nbors;
	while (nbors)
	{
		tmp = find_room_id(rooms, nbors->room.k, nbors->room.id);
		if (tmp)
		{
			if (find_nbors(tmp->nbors, key_table(room->name), room->id))
			{
				find_and_rm_nbors(&room->nbors, nbors->room.k, nbors->room.id);
				nbors = (nbors->next ? nbors->next : NULL);
				find_and_rm_nbors(&tmp->nbors, key_table(room->name), room->id);
			}
			else
				nbors = nbors->next;
		}
		else
			nbors = nbors->next;
	}
}

static void	help_change_direct(t_init_cond *cond, t_room **rooms, \
															t_nbors *stack)
{
	t_room	*tmp;
	t_room	*room;

	room = find_room_id(rooms, stack->room.k, stack->room.id);
	tmp = find_room_id(rooms, cond->end.k, cond->end.id);
	if ((key_table(room->name) == cond->start.k || room->id == cond->start.id))
	{
		room = find_room_id(rooms, tmp->nbors->room.k, tmp->nbors->room.id);
		ft_rm_first_nbors(&(tmp->nbors));
		ft_add_last_nbors(&(room->nbors), ft_nbors_new(key_table(tmp->name), \
														tmp->id, cond->fd));
		tmp = room;
	}
	while ((key_table(room->name) != cond->start.k || \
												room->id != cond->start.id))
	{
		room = find_room_id(rooms, tmp->nbors->room.k, tmp->nbors->room.id);
		ft_rm_first_nbors(&(tmp->nbors));
		ft_add_last_nbors(&(room->nbors), ft_nbors_new(key_table(tmp->name), \
														tmp->id, cond->fd));
		tmp = room;
	}
}

static void	change_direct(t_init_cond *cond, t_room **rooms)
{
	t_room	*tmp;
	t_nbors	*stack;
	t_nbors	*nbors;

	tmp = find_room_id(rooms, cond->end.k, cond->end.id);
	nbors = tmp->nbors;
	stack = NULL;
	while (nbors)
	{
		ft_add_last_nbors(&stack, ft_nbors_new(nbors->room.k, \
											nbors->room.id, cond->fd));
		nbors = nbors->next;
	}
	while (stack)
	{
		help_change_direct(cond, rooms, stack);
		ft_rm_first_nbors(&stack);
	}
}

void		delete_unused(t_init_cond *cond, t_room **rooms)
{
	size_t	i;
	t_room	*room;

	i = 0;
	while (i != SIZE_OF_TABLE)
	{
		if (*(rooms + i))
		{
			(*(rooms + i))->level = -1;
			check_unused(rooms, *(rooms + i));
			room = (*(rooms + i))->next;
			while (room)
			{
				room->level = -1;
				check_unused(rooms, room);
				room = room->next;
			}
		}
		i++;
	}
	change_direct(cond, rooms);
	set_path(rooms);
}

void		fix_paths(t_init_cond *cond, t_room **rooms)
{
	t_room	*tmp;
	t_room	*room;

	room = find_room_id(rooms, cond->end.k, cond->end.id);
	while (room->id != cond->start.id || key_table(room->name) != cond->start.k)
	{
		tmp = find_room_id(rooms, room->from.k, room->from.id);
		if (tmp->path0)
		{
			tmp->path0 = 0;
			ft_add_nbors(&tmp->nbors, ft_nbors_new(key_table(room->name), \
														room->id, cond->fd));
			room = tmp;
		}
	}
}
