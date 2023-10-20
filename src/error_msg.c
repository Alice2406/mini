/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:10:34 by jmorvan           #+#    #+#             */
/*   Updated: 2023/06/21 13:35:02 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	error_joinmsg(char *name, char *msg, int status)
{
	char	*tmp;

	g_value = status;
	tmp = ft_strjoin(name, msg);
	if (!tmp)
	{
		write(2, "Malloc error in error_joinmsg !\n", 32);
		return (2);
	}
	write(2, tmp, ft_strlen(tmp));
	free(tmp);
	return (1);
}

int	perror_msg(char *str, int error)
{
	char	*tmp;

	g_value = 1;
	tmp = strerror(error);
	str = ft_strjoin(str, tmp);
	if (!str)
		return (2);
	tmp = ft_strjoin(str, "\n");
	free(str);
	if (!tmp)
		return (2);
	write(2, tmp, ft_strlen(tmp));
	free(tmp);
	return (1);
}

int	error_msg(char *msg, int status)
{
	g_value = status;
	if (msg)
		write(2, msg, ft_strlen(msg));
	return (1);
}
