/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:28:21 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/08 11:40:14 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_size(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_itoa2(long int n, char *num, int l)
{
	int	np;

	np = 0;
	if (n < 0)
	{
		n *= -1;
		np = 1;
	}
	if (n == 0)
		num[0] = '0';
	while (n != 0)
	{
		num[--l] = n % 10 + '0';
		n = n / 10;
	}
	if (np == 1)
		num[0] = '-';
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		l;

	l = ft_malloc_size((long int)n);
	num = ft_calloc(sizeof(char), (l + 1));
	if (!num)
		return (NULL);
	num = ft_itoa2((long int)n, num, l);
	return (num);
}
