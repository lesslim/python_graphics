/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:50:13 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/16 01:40:02 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (dst || src)
	{
		while (n && *((unsigned char *)src) != (unsigned char)c)
		{
			*((unsigned char *)dst) = *((unsigned char *)src);
			dst++;
			src++;
			n--;
		}
		if (*((unsigned char *)src) == (unsigned char)c && n != 0)
		{
			*((unsigned char *)dst) = *((unsigned char *)src);
			dst++;
		}
		if (n == 0)
			dst = NULL;
	}
	return (dst);
}
