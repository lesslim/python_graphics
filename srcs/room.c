/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:22:11 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:41:09 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_room(t_room **room, const char *line)
{
	size_t	size;

	size = 0;
	while (*(line + size) && !ft_isspace(*(line + size)))
		size++;
	if (!((*room)->name = (char *)malloc(sizeof(char) * (size + 1))))
		ft_exit(-1, NULL, -2);
	*((*room)->name + size) = '\0';
	while (--size)
		*((*room)->name + size) = *(line + size);
	*(*room)->name = *line;
	(*room)->path = 0;
	(*room)->path0 = 0;
	(*room)->level = -1;
	(*room)->from.k = -1;
	(*room)->from.id = -1;
	(*room)->nbors = NULL;
	(*room)->next = NULL;
}

static int	check_double_room(t_room **rooms, char *line, int key)
{
	size_t	i;
	t_room	*room;

	i = 0;
	while (*(line + i) != ' ')
		i++;
	*(line + i) = '\0';
	room = *(rooms + key);
	while (room)
	{
		if (!ft_strcmp(line, room->name))
		{
			*(line + i) = ' ';
			return (1);
		}
		room = room->next;
	}
	*(line + i) = '\0';
	return (0);
}

static int	ft_add_new_room(t_init_cond *cond, t_room ***rooms, \
										const char *line, int key)
{
	int		id;
	t_room	*room;
	t_room	*temp;

	if (*(*rooms + key) && check_double_room(*rooms, (char *)line, key))
		ft_exit(cond->fd, NULL, -9);
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		ft_exit(-1, NULL, -2);
	id = 0;
	if (*(*rooms + key))
	{
		id++;
		temp = *(*rooms + key);
		while (temp->next)
		{
			id++;
			temp = temp->next;
		}
		temp->next = room;
	}
	else
		*(*rooms + key) = room;
	room->id = id;
	init_room(&room, line);
	return (id);
}

static t_id	ft_room(t_init_cond *cond, const char *line, t_room ***room)
{
	t_id	id;

	id.k = key_table(line);
	id.id = ft_add_new_room(cond, room, line, id.k);
	return (id);
}

void		add_room(char *line, t_init_cond **cond, t_room ***room, int code)
{
	t_id	id;

	if (code == FALSE)
		ft_exit((*cond)->fd, line, -1);
	light_printf("%s\n", line);
	if (code == START || code == END)
	{
		free(line);
		if (get_next_line((*cond)->fd, &line) > 0 && who_is_it(line) == ROOM)
			id = ft_room(*cond, line, room);
		else
			ft_exit((*cond)->fd, line, -1);
		light_printf(line ? "%s\n" : "", line);
		if (code == START)
			(*cond)->start.k = id.k;
		else
			(*cond)->end.k = id.k;
		if (code == START)
			(*cond)->start.id = id.id;
		else
			(*cond)->end.id = id.id;
	}
	else
		ft_room(*cond, line, room);
	free(line);
}
