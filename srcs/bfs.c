/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 06:37:06 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:28:01 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	level_bfs(t_nbors **stack, t_room *room_a, t_room **room_b, \
															t_init_cond *cond)
{
	t_nbors	*tmp;

	(*room_b)->from.id = room_a->id;
	(*room_b)->from.k = key_table(room_a->name);
	(*room_b)->level = room_a->level + 1;
	if ((*room_b)->id == cond->end.id && \
									key_table((*room_b)->name) == cond->end.k)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = NULL;
			*stack = tmp;
		}
		return ((*room_b)->level);
	}
	ft_add_last_nbors(stack, ft_nbors_new(key_table((*room_b)->name), \
													(*room_b)->id, cond->fd));
	return (0);
}

static int	deep_help_bfs(t_init_cond *cond, t_room *room_a, t_room *room_b, \
															t_nbors *stack)
{
	int		c;

	if (!room_a->path && !room_b->path)
	{
		if ((c = level_bfs(&stack, room_a, &room_b, cond)))
			return (c);
	}
	else if (room_a->path && !find_nbors(room_b->nbors, \
										key_table(room_a->name), room_a->id))
	{
		if ((c = level_bfs(&stack, room_a, &room_b, cond)))
			return (c);
	}
	else if (room_a->path && !find_nbors(room_a->nbors, \
											room_a->from.k, room_a->from.id))
	{
		if ((c = level_bfs(&stack, room_a, &room_b, cond)))
			return (c);
	}
	return (0);
}

static int	help_bfs(t_init_cond *cond, t_room **rooms, t_room *room_a, \
														t_nbors *stack)
{
	int		c;
	t_room	*room_b;
	t_nbors	*nbors;

	nbors = room_a->nbors;
	while (nbors)
	{
		room_b = find_room_id(rooms, nbors->room.k, nbors->room.id);
		if (room_b->level == -1)
		{
			if (!room_a->path && room_b->path && \
				(room_b == find_room_id(rooms, cond->end.k, cond->end.id) \
											|| clever_if(rooms, room_b)))
			{
				if ((c = level_bfs(&stack, room_a, &room_b, cond)))
					return (c);
			}
			else if ((c = deep_help_bfs(cond, room_a, room_b, stack)))
				return (c);
		}
		nbors = nbors->next;
	}
	return (0);
}

int			bfs(t_init_cond *cond, t_room **rooms)
{
	int		c;
	t_nbors	*stack;
	t_room	*room;

	stack = ft_nbors_new(cond->start.k, cond->start.id, cond->fd);
	room = find_room_id(rooms, cond->start.k, cond->start.id);
	room->level = 0;
	while (stack)
	{
		room = find_room_id(rooms, stack->room.k, stack->room.id);
		if ((c = help_bfs(cond, rooms, room, stack)))
			return (c);
		ft_rm_first_nbors(&stack);
	}
	room = find_room_id(rooms, cond->end.k, cond->end.id);
	return (room->level);
}
