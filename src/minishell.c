/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:56:57 by jmorvan           #+#    #+#             */
/*   Updated: 2023/06/29 15:02:56 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

unsigned char	g_value = 0;

void	get_prompt(t_shell *shell)
{
	while (1)
	{
		if (handle_signal(shell, 1))
			break ;
		shell->line = readline("minishell > ");
		if (ignore_signal(shell))
			break ;
		if (shell->line)
			add_history(shell->line);
		else
			break ;
		if (!ft_strncmp(shell->line, "exit", 4))
			break ;
		if (parsing(shell))
			printf("error in parsing\n");
		free(shell->line);
		rl_on_new_line();
	}
	clear_history();
	free(shell->line);
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	ft_bzero(&shell, sizeof(shell));
	if (handle_signal(&shell, 0))
		return (1);
	if (create_env(&shell, env))
	{
		clean_gc(&shell.gc, 0);
		return (1);
	}
	get_prompt(&shell);
	clean_gc(&shell.gc, 0);
	printf("last exe return value : %d\nbye\n", g_value);
	return (0);
}
