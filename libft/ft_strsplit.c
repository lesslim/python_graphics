/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:16:52 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/13 18:40:07 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	int		i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			num++;
		i++;
	}
	return (num);
}

static char		**back_ft_split(char const *s, char c, char **split)
{
	int		i;
	int		j;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			j = 0;
			while (s[j] != c && s[j] != '\0')
				j++;
			if (!(split[i] = (char *)malloc(sizeof(char) * (j + 1))))
				return (NULL);
			j = 0;
			while (*s != c && *s != '\0')
				split[i][j++] = *(s++);
			split[i][j] = '\0';
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return ((char **)s);
	if (!(split = (char **)malloc(sizeof(char *) * count(s, c) + 1)))
		return (NULL);
	split = back_ft_split(s, c, split);
	return (split);
}
