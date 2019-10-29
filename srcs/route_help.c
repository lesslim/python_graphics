/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 08:34:59 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:42:58 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	length(t_init_cond *cond, t_room **rooms, int len)
{
	t_nbors	*nbors;
	t_nbors	*stack;
	t_room	*tmp;

	stack = NULL;
	tmp = find_room_id(rooms, cond->start.k, cond->start.id);
	nbors = tmp->nbors;
	while (nbors)
	{
		ft_add_last_nbors(&stack, ft_nbors_new(nbors->room.k, \
											nbors->room.id, cond->fd));
		nbors = nbors->next;
	}
	while (stack)
	{
		len = 1;
		tmp = find_room_id(rooms, stack->room.k, stack->room.id);
		while (key_table(tmp->name) != cond->end.k || tmp->id != cond->end.id)
		{
			len++;
			tmp = find_room_id(rooms, tmp->nbors->room.k, tmp->nbors->room.id);
		}
		(find_room_id(rooms, stack->room.k, stack->room.id))->level = len;
		ft_rm_first_nbors(&stack);
	}
}

t_path	*path_is_free(t_room **rooms, t_ant *ant, t_path *path)
{
	t_path		*tmp;
	t_room		*room;
	t_ant		*ants;

	if (path->len == 1)
		return (path);
	tmp = path;
	while (tmp)
	{
		if (tmp->ants > 0)
		{
			ants = ant;
			room = find_room_id(rooms, tmp->room.k, tmp->room.id);
			while (ants)
			{
				if (ants->room && room == ants->room)
					break ;
				ants = ants->next;
			}
			if (!ants)
				return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
