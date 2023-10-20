/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:17:07 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/06 12:34:53 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_stock_buff(char *buff, char *stock)
{
	char	*temp;

	if (!stock)
		return (NULL);
	temp = ft_strjoin_gnl(stock, buff);
	free(stock);
	return (temp);
}

static char	*read_fd(char *stock, int fd)
{
	int		l_read;
	char	*buff;

	if (!stock)
		stock = ft_calloc_gnl(1, 1);
	buff = ft_calloc_gnl(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff || !stock)
		return (NULL);
	l_read = 1;
	while (l_read > 0)
	{
		l_read = read(fd, buff, BUFFER_SIZE);
		if (l_read < 0)
		{
			free(buff);
			free(stock);
			return (NULL);
		}
		buff[l_read] = 0;
		stock = join_stock_buff(buff, stock);
		if (check_for_nl_gnl(buff) != -1)
			break ;
	}
	free(buff);
	return (stock);
}

static char	*get_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (i == 0 && stock[i] != '\n')
		return (NULL);
	line = ft_calloc_gnl(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] && stock[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*get_rest(char *stock)
{
	char	*new_stock;
	int		i;
	int		l;

	i = check_for_nl_gnl(stock);
	if (i == -1)
	{
		free(stock);
		return (NULL);
	}
	else
		l = (ft_strlen_gnl(stock) - i);
	new_stock = ft_calloc_gnl(sizeof(char), (l + 1));
	if (!new_stock)
		return (NULL);
	l = 0;
	while (stock[i + l + 1])
	{
		new_stock[l] = stock[i + l + 1];
		l++;
	}
	free(stock);
	return (new_stock);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_fd(stock, fd);
	if (!stock)
		return (NULL);
	line = get_line(stock);
	stock = get_rest(stock);
	if (stock && stock[0] == '\0')
	{
		free(stock);
		stock = NULL;
	}
	return (line);
}
