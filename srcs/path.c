/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 04:33:39 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 01:30:51 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_path_new(int len, t_id room, int ants, int fd)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		ft_exit(fd, NULL, -2);
	path->room = room;
	path->len = len;
	path->ants = ants;
	path->next = NULL;
	return (path);
}

void	ft_add_path(t_path **path, t_path *new)
{
	t_path	*tmp;

	if (new)
	{
		if (!(*path))
			*path = new;
		else
		{
			tmp = *path;
			*path = new;
			new->next = tmp;
		}
	}
}

void	ft_free_path(t_path **path)
{
	t_path	*tmp;

	tmp = *path;
	while (*path)
	{
		tmp = (*path)->next;
		free(*path);
		*path = NULL;
		*path = tmp;
	}
}
