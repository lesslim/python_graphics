/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 04:38:32 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:31:59 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	help_freedom(t_room ***rooms, size_t i)
{
	t_room		*tmp;
	t_room		*room;
	t_nbors		*nbors;

	room = *(*rooms + i);
	while (room)
	{
		tmp = room->next;
		free(room->name);
		if (room->nbors)
			while (room->nbors)
			{
				nbors = room->nbors;
				room->nbors = room->nbors->next;
				free(nbors);
			}
		free(room);
		room = tmp;
	}
	*(*rooms + i) = NULL;
}

void		freedom(t_init_cond **cond, t_room ***rooms)
{
	size_t		i;

	i = 0;
	while (i != SIZE_OF_TABLE)
	{
		if (*(*rooms + i))
			help_freedom(rooms, i);
		i++;
	}
	free(*rooms);
	free(*cond);
}
