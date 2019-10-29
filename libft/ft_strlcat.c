/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:04:47 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/12 14:01:15 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	num;
	char	*tmp;

	tmp = dst;
	num = size;
	while (*tmp != '\0' && num != 0 && num-- != 1)
		tmp++;
	if (size == 0 || *tmp != '\0')
		return (size - num + ft_strlen(src));
	while (*src != '\0' && num != 0 && num-- != 1)
		*tmp++ = *src++;
	*tmp = '\0';
	if (*src != '\0')
		while (*(++src) != '\0')
			num--;
	return (size - num);
}
