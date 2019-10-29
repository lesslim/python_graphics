/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 04:42:52 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:52:10 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	spec_atoi(const char *str)
{
	long	num;
	size_t	i;
	size_t	k;

	i = (*str == '+' ? 1 : 0);
	while (ft_isdigit(*(str + i)))
		i++;
	if (*(str + i))
		return (-1);
	num = 0;
	k = i - 1;
	while (i && ft_isdigit(*(str + i - 1)))
	{
		num += (*(str + i - 1) - '0') * ft_pow(10, k - (i - 1));
		if (num > (long)INT_MAX)
			return (-1);
		i--;
	}
	return ((int)num);
}

static void	count_of_ants(t_init_cond **cond)
{
	char	*line;

	if (get_next_line((*cond)->fd, &line) > 0)
	{
		while (ft_strcmp(line, COM_START) && ft_strcmp(line, COM_END) && \
																*line == '#')
		{
			free(line);
			if ((get_next_line((*cond)->fd, &line)) <= 0)
				ft_exit((*cond)->fd, line, -1);
		}
		(*cond)->ants = spec_atoi(line);
		if ((*cond)->ants <= 0)
			ft_exit((*cond)->fd, line, -3);
		light_printf("%s\n", line);
		free(line);
	}
	else
		ft_exit((*cond)->fd, NULL, -3);
}

static int	help_parse(char **line, t_room ***room, int fd)
{
	int		code;

	light_printf("%s\n", *line);
	edge(*line, room, who_is_it(*line), fd);
	free(*line);
	code = get_next_line(fd, line);
	return (code);
}

void		parse(t_init_cond **cond, t_room ***room)
{
	int		code;
	char	*line;

	count_of_ants(cond);
	while (get_next_line((*cond)->fd, &line) > 0)
	{
		code = who_is_it(line);
		if (code == EDGE)
			break ;
		else if (code != IGNOR)
			add_room(line, cond, room, code);
		else
		{
			light_printf("%s\n", line);
			free(line);
		}
	}
	if ((*cond)->start.k < 0 || (*cond)->start.id < 0 || \
				(*cond)->end.k < 0 || (*cond)->start.id < 0)
		ft_exit((*cond)->fd, line, -4);
	while (line && code > 0)
		code = help_parse(&line, room, (*cond)->fd);
	free(line);
}
