/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:06:23 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/15 18:57:35 by nhamill          ###   ########.fr       */
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

void		ft_putnbr(int n)
{
	int		i;
	int		tmp;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if ((n == -2147483648) && (n = 147483648))
			ft_putchar(2 + 48);
		else
			n *= -1;
	}
	tmp = n;
	while ((tmp != 0) && (tmp /= 10))
		i++;
	if (n == 0)
		ft_putchar(0 + 48);
	else
		while (i != -1)
		{
			tmp = n / disch(i);
			ft_putchar(tmp + 48);
			n -= tmp * disch(i);
			i--;
		}
}
