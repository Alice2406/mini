/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:26:00 by jmorvan           #+#    #+#             */
/*   Updated: 2023/06/19 14:17:26 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
Print the env (REMOVE FOR FINAL PUSH).
*/
// void	print_env(char **env)
// {
// 	int	i = 0;
// 	if (!env)
// 		return ;
// 	while (env[i])
// 	{
// 		printf("%s\n", env[i]);
// 		i++;
// 	}
// }

/*
Add + 1 to the variable SHLVL in the environment.
Do nothing if SHLVL is not find in the environment.
*/
int	add_shlvl(t_shell *shell)
{
	int		i;
	char	*shlvl;

	i = -1;
	while (shell->env[++i])
	{
		if (!ft_strncmp(shell->env[i], "SHLVL=", 6))
		{
			shlvl = ft_itoa(ft_atoi(shell->env[i] + 6) + 1);
			if (!shlvl)
				return (1);
			free_in_gc(&shell->gc, shell->env[i]);
			shell->env[i] = gc_malloc((sizeof(char) * (ft_strlen(shlvl) + 7)),
					&shell->gc, 0);
			if (!shell->env)
			{
				free(shlvl);
				return (1);
			}
			ft_memcpy(shell->env[i], "SHLVL=", 6);
			ft_memcpy(shell->env[i] + 6, shlvl, ft_strlen(shlvl) + 1);
			free(shlvl);
		}
	}
	return (0);
}

/*
Copy the environment ENV in our new environment (inside the struct SHELL).
*/
int	cpy_env(t_shell *shell, char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = gc_malloc(sizeof(char *) * (ft_tab_size(env) + 1), &shell->gc, 0);
	shell->env = new_env;
	if (!new_env)
		return (1);
	while (env[i])
	{
		new_env[i] = gc_malloc((sizeof(char) * (ft_strlen(env[i]) + 1)),
				&shell->gc, 0);
		if (!new_env[i])
			return (1);
		ft_memcpy(new_env[i], env[i], (ft_strlen(env[i]) + 1));
		i++;
	}
	new_env[i] = NULL;
	return (0);
}

/*
create_new_env : Function has more than 25 lines ¯\_(ツ)_/¯
*/
void	cpy_in_new_env(char **new_env, char *pwd)
{
	ft_memcpy(new_env[0], "PWD=", 5);
	ft_memcpy(new_env[0] + 4, pwd, ft_strlen(pwd));
	ft_memcpy(new_env[1], "OLDPWD=", 8);
	ft_memcpy(new_env[1] + 7, pwd, ft_strlen(pwd));
	ft_memcpy(new_env[2], "SHLVL=1", 8);
	free(pwd);
}

/*
Create a new environment for the shell with the variable :
- PWD : contain the current PWD.
- OLDPWD : contain the current PWD and change to the old one when cd is use.
- SHLVL : show the shell level.
*/
int	create_new_env(t_shell *shell)
{
	char	**new_env;
	char	*pwd;

	new_env = gc_malloc(sizeof(char *) * 4, &shell->gc, 0);
	shell->env = new_env;
	pwd = getcwd(NULL, 0);
	if (!pwd || !new_env)
		return (1);
	new_env[0] = gc_malloc((sizeof(char) * (ft_strlen(pwd) + 5)),
			&shell->gc, 0);
	new_env[1] = gc_malloc((sizeof(char) * (ft_strlen(pwd) + 8)),
			&shell->gc, 0);
	new_env[2] = gc_malloc((sizeof(char) * 8), &shell->gc, 0);
	if (!new_env[0] || !new_env[1] || !new_env[2])
	{
		free(pwd);
		return (1);
	}
	cpy_in_new_env(new_env, pwd);
	new_env[3] = NULL;
	return (0);
}

/*
Copy the environment in ENV or create a new one if ENV is empty.
*/
int	create_env(t_shell *shell, char **env)
{
	if (!env[0])
	{
		if (create_new_env(shell))
			return (1);
		return (0);
	}
	if (cpy_env(shell, env))
		return (1);
	if (add_shlvl(shell))
		return (1);
	return (0);
}
