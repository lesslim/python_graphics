/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:16:52 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/16 20:15:41 by nhamill          ###   ########.fr       */
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

static t_list	*back(char const *s, char c, t_list *split)
{
	int		j;
	char	*str;
	t_list	*head;

	head = split;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			j = 0;
			while (s[j] != c && s[j] != '\0')
				j++;
			str = (char *)malloc(sizeof(char) * (j + 1));
			j = 0;
			while (*s != c && *s != '\0')
				str[j++] = *(s++);
			str[j] = '\0';
			split->next = ft_lstnew(str, j + 1);
			free(str);
			split = split->next;
		}
	}
	return (head);
}

t_list			*ft_lstsplit(char const *s, char c)
{
	int		j;
	char	*str;
	t_list	*split;

	if (s == NULL)
		return (NULL);
	if (!(split = (t_list *)malloc(sizeof(t_list) * count(s, c) + 1)))
		return (NULL);
	while (*s == c && *s != '\0')
		s++;
	if (*s != '\0')
	{
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j++;
		str = (char *)malloc(sizeof(char) * (j + 1));
		j = 0;
		while (*s != c && *s != '\0')
			str[j++] = *(s++);
		str[j] = '\0';
		split = ft_lstnew(str, j + 1);
		free(str);
	}
	split = back(s, c, split);
	return (split);
}
