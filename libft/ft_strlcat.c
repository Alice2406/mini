/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:27:19 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/08 11:49:59 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	if (!dst)
		return (size + ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	if (i <= (size - 1) && size != 0)
	{
		l = (ft_strlen(dst) + ft_strlen(src));
		while (src[j] && j < size - i - 1)
		{
			dst[j + i] = src[j];
			j++;
		}
		if (i < size)
			dst[j + i] = '\0';
	}
	else
		l = (size + ft_strlen(src));
	return (l);
}
