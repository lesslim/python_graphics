/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 00:15:52 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/12 13:01:35 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	leng;
	char	*little_needle;
	char	*little_haystack;

	if (*needle == '\0')
		return ((char *)haystack);
	while ((*haystack != '\0') && (len-- != 0))
	{
		little_needle = (char *)needle;
		if (*haystack == *little_needle)
		{
			leng = len + 1;
			little_haystack = (char *)haystack;
			while ((*little_haystack == *little_needle) && \
				(*little_haystack != '\0') && leng--)
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
