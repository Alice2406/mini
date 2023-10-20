/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:37:48 by jmorvan           #+#    #+#             */
/*   Updated: 2023/06/27 16:51:21 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
The function that handle the CTRL-C signal by making
him skip a line in the prompt.
*/
void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
//	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/*
Change the CTRL-C signal and make him do skip a line in the prompt,
and also ignore the CRTL-\.
*/
int	handle_signal(t_shell *shell, int s)
{
	if (!s)
	{
		shell->ctrl_bs.sa_handler = SIG_IGN;
		if (sigaction(SIGQUIT, &shell->ctrl_bs, NULL))
			return (perror_msg("sigaction", errno));
		shell->ctrl_c.sa_handler = &handle_sigint;
		if (sigaction(SIGINT, &shell->ctrl_c, &shell->old_ctrl_c))
			return (perror_msg("sigaction", errno));
	}
	else
	{
		shell->ctrl_c.sa_handler = &handle_sigint;
		if (sigaction(SIGINT, &shell->ctrl_c, NULL))
			return (perror_msg("sigaction", errno));
	}
	return (0);
}

/*
Make the current processus ignore the ctrl-C signal.
*/
int	ignore_signal(t_shell *shell)
{
	shell->ctrl_c.sa_handler = SIG_IGN;
	if (sigaction(SIGINT, &shell->ctrl_c, NULL))
		return (perror_msg("sigaction", errno));
	return (0);
}

/*
Change the ctrl-C and ctrl-\ signal to there default action.
*/
int	default_signal(t_shell *shell)
{
	shell->ctrl_bs.sa_handler = SIG_DFL;
	if (sigaction(SIGQUIT, &shell->ctrl_bs, NULL))
		return (perror_msg("sigaction", errno));
	if (sigaction(SIGINT, &shell->old_ctrl_c, NULL))
		return (perror_msg("sigaction", errno));
	return (0);
}
