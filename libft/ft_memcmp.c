/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:39:12 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/16 19:19:05 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 || s2)
	{
		while (*(unsigned char *)s1 == *(unsigned char *)s2 && n-- != 1)
		{
			s1++;
			s2++;
		}
		if (n != 0)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}
