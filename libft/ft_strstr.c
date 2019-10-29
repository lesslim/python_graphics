/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:23:20 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/09 02:41:21 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*little_needle;
	char	*little_haystack;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		little_needle = (char *)needle;
		if (*haystack == *little_needle)
		{
			little_haystack = (char *)haystack;
			while ((*little_haystack == *little_needle) && \
	(*little_haystack != '\0'))
			{
				little_haystack++;
				little_needle++;
			}
			if (*little_needle == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
