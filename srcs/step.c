/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:28:16 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 23:08:27 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	help_count_of_steps(t_nbors *steps, \
								int *l_max, int *sum_dif_l, int *n)
{
	t_nbors	*temp;

	temp = steps;
	while (temp)
	{
		(*n)++;
		if (temp->room.k > *l_max)
			*l_max = temp->room.k;
		temp = temp->next;
	}
	temp = steps;
	while (temp)
	{
		*sum_dif_l += *l_max - temp->room.k;
		temp = temp->next;
	}
}

static int	count_of_steps(t_init_cond *cond, t_nbors *steps, int n, int var)
{
	int		l_max;
	int		sum_dif_l;
	t_nbors	*temp;

	l_max = 0;
	sum_dif_l = 0;
	help_count_of_steps(steps, &l_max, &sum_dif_l, &n);
	while (steps)
	{
		temp = steps;
		steps = steps->next;
		free(temp);
	}
	free(steps);
	if (!n)
		return (INT_MAX);
	var = cond->ants - n - sum_dif_l;
	return (l_max + var / n + (var % n ? 1 : 0));
}

static int	ordinary_path(t_init_cond *cond, t_room **rooms, t_nbors *nbors)
{
	t_room	*tmp;
	t_room	*start;

	start = find_room_id(rooms, cond->start.k, cond->start.id);
	while (nbors)
	{
		tmp = find_room_id(rooms, nbors->room.k, nbors->room.id);
		if (tmp == start)
			return (1);
		nbors = nbors->next;
	}
	return (0);
}

static int	cycle(t_init_cond *cond, t_room **rooms, t_room **room)
{
	int		len;
	t_room	*tmp;
	t_nbors	*nbors;

	len = 1;
	while ((*room)->id != cond->start.id || \
								key_table((*room)->name) != cond->start.k)
	{
		nbors = (*room)->nbors;
		while (nbors)
		{
			tmp = find_room_id(rooms, nbors->room.k, nbors->room.id);
			if (find_nbors((*room)->nbors, key_table(tmp->name), tmp->id) && \
				!find_nbors(tmp->nbors, key_table((*room)->name), (*room)->id) \
				&& (tmp->path || tmp->path0))
			{
				*room = find_room_id(rooms, nbors->room.k, nbors->room.id);
				len++;
				break ;
			}
			nbors = nbors->next;
		}
	}
	return (len);
}

int			ft_step(t_init_cond *cd, t_room **rooms)
{
	t_nbors	*steps;
	t_nbors	*stack;
	t_nbors	*ns;
	t_room	*room;

	steps = NULL;
	stack = NULL;
	room = find_room_id(rooms, cd->end.k, cd->end.id);
	if (ordinary_path(cd, rooms, room->nbors))
		return (1);
	ns = room->nbors;
	while (ns)
	{
		room = find_room_id(rooms, ns->room.k, ns->room.id);
		if (room->path || room->path0)
			ft_add_nbors(&stack, ft_nbors_new(ns->room.k, ns->room.id, cd->fd));
		ns = ns->next;
	}
	while (stack)
	{
		room = find_room_id(rooms, stack->room.k, stack->room.id);
		ft_add_nbors(&steps, ft_nbors_new(cycle(cd, rooms, &room), 0, cd->fd));
		ft_rm_first_nbors(&stack);
	}
	return (count_of_steps(cd, steps, 0, 0));
}
