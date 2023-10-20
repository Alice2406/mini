/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:30:30 by jmorvan           #+#    #+#             */
/*   Updated: 2023/06/19 15:35:21 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_words_count(const char *s)
{
	int	i;
	int	wc;
	int	ws;

	i = 0;
	wc = 0;
	ws = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ':')
			ws = 1;
		if (s[i] == ':' && ws == 1)
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

char	*ft_malloc(char *s, char *str, char *exe, int *i)
{
	int	wl;
	int	j;

	j = 0;
	wl = (*i);
	while (s[*i] != ':' && s[*i] != '\0')
		(*i)++;
	str = malloc(sizeof(char) * ((*i) - wl + 2 + ft_strlen(exe)));
	if (!str)
		return (NULL);
	while (wl < (*i))
	{
		str[j] = s[wl];
		wl++;
		j++;
	}
	str[j++] = '/';
	wl = -1;
	while (exe[++wl])
		str[j + wl] = exe[wl];
	str[j + wl] = '\0';
	return (str);
}

void	*ft_free_alloc(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

char	**path_split(char const *s, char *exe)
{
	char	**str;
	int		wc;
	int		i;
	int		j;

	if (!exe || !s)
		return (NULL);
	i = 0;
	j = 0;
	wc = ft_words_count(s);
	str = malloc(sizeof(char *) * (wc + 1));
	if (!str)
		return (NULL);
	while (j < wc)
	{
		while (s[i] == ':' && s[i] != '\0')
			i++;
		str[j] = ft_malloc((char *)s, str[j], exe, &i);
		if (!str[j])
			return (ft_free_alloc(str, j));
		j++;
	}
	str[j] = NULL;
	return (str);
}

/*
Return a char** that have all possible executable path of EXE
with the variable PATH in the environement. return NULL if there is no
environement or if PATH is unset.
*/
char	**get_path(t_shell *shell, char *exe)
{
	int	i;

	if (!shell->env)
		return (NULL);
	i = 0;
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], "PATH=", 4))
			return (path_split(shell->env[i], exe));
		i++;
	}
	return (NULL);
}
