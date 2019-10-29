/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:19:10 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 01:33:46 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		one_del(char *line, t_room ***room, size_t i, int fd)
{
	int		key1;
	int		key2;
	t_room	*r1;
	t_room	*r2;

	*(line + i) = '\0';
	key1 = key_table(line);
	r1 = find_room(line, *room, key1);
	key2 = key_table(line + i + 1);
	r2 = find_room(line + i + 1, *room, key2);
	if (!r1 || !r2)
		exit(-1);
	if (r1 == r2)
		return ;
	ft_add_nbors_to_room(&r1, ft_nbors_new(key2, r2->id, fd));
	ft_add_nbors_to_room(&r2, ft_nbors_new(key1, r1->id, fd));
}

static size_t	there_are_edge(char *line, t_room **rooms, size_t i)
{
	t_room	*r1;
	t_room	*r2;

	*(line + i) = '\0';
	r1 = find_room(line, rooms, key_table(line));
	r2 = find_room(line + i + 1, rooms, key_table(line + i + 1));
	*(line + i) = '-';
	if (r1 && r2)
		return (1);
	return (0);
}

static size_t	double_del(char *line, t_room ***rooms, size_t i)
{
	size_t	del;
	size_t	num;
	size_t	tmp;
	size_t	count;

	num = 0;
	while (*(line + i + num) == '-')
		num++;
	count = 0;
	while (num--)
		if ((tmp = there_are_edge(line, *rooms, i + num)))
		{
			del = num;
			count += tmp;
		}
	if (count == 1)
		return (i + del);
	else
		return (0);
}

static size_t	check_edge(char *line, t_room ***room)
{
	size_t	i;
	size_t	tmp;
	size_t	del;
	size_t	count;

	count = 0;
	i = (*line == '-' ? 1 : 0);
	while (*(line + i) && *(line + i + 1))
	{
		while (*(line + i) && *(line + i) != '-')
			i++;
		if (*(line + i))
		{
			tmp = double_del(line, room, i);
			if (tmp)
			{
				count++;
				del = tmp;
			}
			while (*(line + i) == '-')
				i++;
		}
	}
	return (count == 1 ? del : 0);
}

void			edge(char *line, t_room ***room, int code, int fd)
{
	size_t	del;

	if (code == FALSE || code == START || code == END || code == ROOM)
		ft_exit(fd, line, -1);
	else if (code == IGNOR)
		return ;
	if ((del = check_edge(line, room)))
		one_del(line, room, del, fd);
	else
		ft_exit(fd, line, -1);
}
