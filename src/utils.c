/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:49:34 by jmorvan           #+#    #+#             */
/*   Updated: 2023/06/26 17:07:59 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strdup_gc(const char *s, t_garbage **gc, int id)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = gc_malloc((sizeof(char) * i + 1), gc, id);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	quit(t_shell *shell)
{
	if (shell->pipe[0] >= 0)
		close(shell->pipe[0]);
	if (shell->pipe[1] >= 0)
		close(shell->pipe[1]);
	if (shell->old_pipe[0] >= 0)
		close(shell->old_pipe[0]);
	if (shell->old_pipe[1] >= 0)
		close(shell->old_pipe[1]);
	clean_gc(&shell->gc, 0);
	exit(g_value);
}
