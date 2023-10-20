/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:19:28 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/08 11:38:58 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A verifier

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
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
