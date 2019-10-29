/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:14:30 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/16 15:32:17 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*tmp;

	tmp = dst;
	while (*src != '\0' && len-- != 0)
		*tmp++ = *src++;
	if (len != 0 && *src == '\0')
		while (len-- != 0)
			*tmp++ = '\0';
	return (dst);
}
