/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:48:52 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/30 22:30:29 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t	i;
	int		tmp;
	char	*str;

	if (n == 0)
		return (str = "0");
	i = 1;
	tmp = n;
	if (n < 0)
		i++;
	while (tmp /= 10)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (n)
	{
		if ((n < 0) && (n *= -1))
			str[0] = '-';
		if (n == -2147483648)
			str[i-- - 1] = '8';
		else
			str[i-- - 1] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
