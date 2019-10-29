/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 00:58:10 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 01:30:22 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	how_many_ants_on_paths(t_init_cond *cond, t_path **path, int step)
{
	int		a;
	int		c;
	t_path	*tmp;

	if ((*path)->len != 1)
	{
		a = cond->ants;
		tmp = *path;
		while (tmp)
		{
			c = step - tmp->len + 1;
			tmp->ants = (c < a ? c : a);
			a -= (c < a ? c : a);
			tmp = tmp->next;
		}
	}
}

static void	if_one(t_room **rooms, t_ant **ants, t_path **tmp, char *flag)
{
	(*ants)->room = find_room_id(rooms, (*tmp)->room.k, (*tmp)->room.id);
	light_printf(*flag ? " L%d-%s" : "L%d-%s", (*ants)->n, (*ants)->room->name);
	*flag = 1;
	(*tmp)->ants--;
}

static void	if_two(t_room **rooms, t_ant **ants, char *flag)
{
	(*ants)->room = find_room_id(rooms, (*ants)->room->nbors->room.k, \
										(*ants)->room->nbors->room.id);
	light_printf(*flag ? " L%d-%s" : "L%d-%s", (*ants)->n, (*ants)->room->name);
	*flag = 1;
}

static void	next_ants(t_init_cond *cond, t_room **rooms, \
									t_ant **ant, t_ant **ants)
{
	if ((*ants)->room && key_table((*ants)->room->name) == cond->end.k \
									&& (*ants)->room->id == cond->end.id)
	{
		*ants = (*ants)->next;
		ft_rm_ant(ant, find_room_id(rooms, cond->end.k, cond->end.id));
	}
	else
		*ants = (*ants)->next;
}

void		route(t_init_cond *cond, t_room **rooms, int step)
{
	char	flag;
	t_ant	*ant;
	t_ant	*ants;
	t_path	*path;
	t_path	*tmp;

	init_ant_and_path(cond, rooms, &ant, &path);
	how_many_ants_on_paths(cond, &path, step);
	while (ant)
	{
		flag = 0;
		ants = ant;
		while (ants)
		{
			if (!ants->room && (tmp = path_is_free(rooms, ant, path)))
				if_one(rooms, &ants, &tmp, &flag);
			else if (ants->room)
				if_two(rooms, &ants, &flag);
			if (!ants->room)
				break ;
			next_ants(cond, rooms, &ant, &ants);
		}
		light_printf("\n");
	}
	ft_free_path(&path);
}
