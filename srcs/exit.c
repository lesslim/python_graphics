/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:58:19 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 23:33:00 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	sys_error(int n)
{
	perror("ERROR");
	exit(n);
}

static void	other_err(int n)
{
	write(2, "\nERROR: ", 8);
	if (n != -2)
	{
		if (n == -1)
			write(2, "invalid string format\n", 22);
		else if (n == -3)
			write(2, "invalid number of ants\n", 23);
		else if (n == -4)
			write(2, "there is no start or end\n", 25);
		else if (n == -5)
			write(2, "no solution\n", 12);
		else if (n == -9)
			write(2, "double room\n", 12);
	}
}

int			ft_exit(int fd, char *str, int n)
{
	char	*line;

	if (n == -2 || n == -7 || n == -8)
		sys_error(n);
	if (n == -6)
	{
		write(1, "Usage: ./lem-in [-s] map\n", 25);
		exit(n);
	}
	if (str)
	{
		light_printf("%s\n", str);
		free(str);
	}
	while (get_next_line(fd, &line) > 0)
	{
		light_printf("%s\n", line);
		free(line);
	}
	other_err(n);
	exit(n);
}
