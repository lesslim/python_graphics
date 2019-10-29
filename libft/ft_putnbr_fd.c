/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:06:23 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/15 18:58:07 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	disch(int power)
{
	int	num;

	num = 1;
	while (power--)
		num *= 10;
	return (num);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	tmp;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if ((n == -2147483648) && (n = 147483648))
			ft_putchar_fd(2 + 48, fd);
		else
			n *= -1;
	}
	tmp = n;
	while ((tmp != 0) && (tmp /= 10))
		i++;
	if (n == 0)
		ft_putchar_fd(0 + 48, fd);
	else
		while (i != -1)
		{
			tmp = n / disch(i);
			ft_putchar_fd(tmp + 48, fd);
			n -= tmp * disch(i);
			i--;
		}
}
