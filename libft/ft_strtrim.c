/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:08:11 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/08 11:53:13 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char c, char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_end(char const *s1, const char *s2)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0 && ft_find(s1[i - 1], s2))
		i--;
	return (i);
}

static void	ft_fill(char *str, const char *s1, size_t end, size_t start)
{
	size_t	i;

	i = 0;
	while (i < (end - start))
	{
		str[i] = s1[start + i];
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	end;
	size_t	start;
	size_t	lm;
	char	*str;

	start = 0;
	lm = 0;
	end = 0;
	while (s1[start] && ft_find(s1[start], s2))
		start++;
	if (start == ft_strlen(s1))
	{
		str = ft_calloc(sizeof(char), (lm + 1));
		if (!str)
			return (NULL);
		return (str);
	}
	end = ft_end(s1, s2);
	lm = (end - start);
	str = ft_calloc(sizeof(char), (lm + 1));
	if (!str)
		return (NULL);
	ft_fill(str, s1, end, start);
	return (str);
}
