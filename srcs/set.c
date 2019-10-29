/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 04:35:24 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/17 04:35:46 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_from(t_room **rooms, int set)
{
	size_t	i;
	t_room	*room;

	i = 0;
	while (i != SIZE_OF_TABLE)
	{
		if (*(rooms + i))
		{
			if ((*(rooms + i))->from.k != set)
				(*(rooms + i))->from.k = set;
			if ((*(rooms + i))->from.id != set)
				(*(rooms + i))->from.id = set;
			room = (*(rooms + i))->next;
			while (room)
			{
				if (room->from.k != set)
					room->from.k = set;
				if (room->from.id != set)
					room->from.id = set;
				room = room->next;
			}
		}
		i++;
	}
}

void	set_level(t_room **rooms, int level)
{
	size_t	i;
	t_room	*room;

	i = 0;
	while (i != SIZE_OF_TABLE)
	{
		if (*(rooms + i))
		{
			if ((*(rooms + i))->level != level)
				(*(rooms + i))->level = level;
			room = (*(rooms + i))->next;
			while (room)
			{
				if (room->level != level)
					room->level = level;
				room = room->next;
			}
		}
		i++;
	}
}

void	set_path(t_room **rooms)
{
	ssize_t	i;
	t_room	*room;

	i = -1;
	while (++i != SIZE_OF_TABLE)
	{
		if (*(rooms + i))
		{
			if ((*(rooms + i))->path0)
			{
				(*(rooms + i))->path = 1;
				(*(rooms + i))->path0 = 0;
			}
			room = (*(rooms + i))->next;
			while (room)
			{
				if (room->path0)
				{
					room->path = 1;
					room->path0 = 0;
				}
				room = room->next;
			}
		}
	}
}
