/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:27:48 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/08 11:56:56 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (start > ft_strlen(s))
	{
		str = ft_calloc(sizeof(char), 1);
		if (!str)
			return (NULL);
		return (str);
	}
	else if ((ft_strlen(s) - start) <= len)
		str = ft_calloc(sizeof(char), (ft_strlen(s) - start + 1));
	else
		str = ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
