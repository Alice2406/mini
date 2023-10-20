/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:17:28 by jmorvan           #+#    #+#             */
/*   Updated: 2023/01/13 13:13:18 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			i;
	int				tof;

	i = 0;
	tof = (int)(nmemb * size);
	if (size && nmemb != (tof / size))
		return (NULL);
	arr = malloc(size * nmemb);
	if (!arr)
		return (NULL);
	while (i != (size * nmemb))
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_for_nl_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen_gnl(s1);
	j = ft_strlen_gnl(s2);
	str = ft_calloc_gnl(sizeof(char), (i + j + 1));
	if (!str)
		return (NULL);
	j = -1;
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[j + i] = s2[j];
	str[j + i] = '\0';
	return (str);
}
