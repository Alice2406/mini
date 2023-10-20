/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:41:57 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/08 11:45:41 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(const char *s, char c)
{
	int	i;
	int	wc;
	int	ws;

	i = 0;
	wc = 0;
	ws = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			ws = 1;
		if (s[i] == c && ws == 1)
		{
			wc++;
			ws = 0;
		}
		i++;
	}
	if (ws == 1)
		wc++;
	return (wc);
}

static char	*ft_malloc(char *s, char *str, char c, int *i)
{
	int	wl;
	int	j;

	j = 0;
	wl = (*i);
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	str = malloc(sizeof(char) * ((*i) - wl + 1));
	if (!str)
		return (NULL);
	while (wl < (*i))
	{
		str[j] = s[wl];
		wl++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static void	ft_free_alloc(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		wc;
	int		i;
	int		j;

	i = 0;
	j = 0;
	wc = ft_words_count(s, c);
	str = ft_calloc(sizeof(char *), (wc + 1));
	if (!str)
		return (NULL);
	while (j < wc)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		str[j] = ft_malloc((char *)s, str[j], c, &i);
		if (!str[j])
		{
			ft_free_alloc(str, j);
			return (NULL);
		}
		j++;
	}
	return (str);
}
