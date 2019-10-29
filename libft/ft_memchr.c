/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:11:22 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/16 01:24:18 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (s == NULL && n == 0)
		return (NULL);
	{
		while (*(unsigned char *)s != (unsigned char)c && n-- != 1)
			s++;
		if (*(unsigned char *)s == (unsigned char)c)
			return ((unsigned char *)s);
	}
	return (NULL);
}
