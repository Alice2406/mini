/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:34:15 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/08 11:45:06 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenn(long int nb)
{
	int	l;

	l = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		l = l * 10;
	}
	return (l);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	l;

	l = ft_lenn(n);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (l != 0)
	{
		ft_putchar_fd(n / l + '0', fd);
		n = n % l;
		l /= 10;
	}
}
