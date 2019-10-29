/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:29:49 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/30 22:19:21 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	disch(int power)
{
	long long	num;

	num = 1;
	while (power--)
		num *= 10;
	return (num);
}

static int			back_ft_atoi(char *dst, int znak)
{
	int			i;
	long long	big_num;

	i = -1;
	big_num = 0;
	while (dst[++i] != '\0')
	{
		big_num += (dst[i] - 48) * disch(ft_strlen(dst) - i - 1);
		if (big_num < 0)
		{
			if (znak == -1)
				return (0);
			return (-1);
		}
	}
	return ((int)big_num * znak);
}

int					ft_atoi(const char *str)
{
	int			i;
	int			znak;
	char		dst[ft_strlen(str) + 1];

	i = 0;
	znak = 1;
	while (*(str + i) == 32 || (*(str + i) > 8 && *(str + i) < 14))
		i++;
	if (*(str + i) == 43 || *(str + i) == 45)
		znak = (*(str + i++) - 44) * -1;
	dst[0] = '\0';
	while (ft_isdigit(*(str + i)))
		ft_strncat(dst, str + i++, 1);
	return (back_ft_atoi(dst, znak));
}
