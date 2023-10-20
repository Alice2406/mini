/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:14:25 by jmorvan           #+#    #+#             */
/*   Updated: 2023/10/20 12:02:12 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	check for unclosed double and simpe quote
*/
int	check_quote(t_shell *shell)
{
	int		i;
	char	c;

	i = 0;
	while (shell->line[i])
	{
		if (shell->line[i] == '\"' || shell->line[i] == '\'')
		{
			c = shell->line[i];
			i++;
			while (shell->line[i] && shell->line[i] != c)
				i++;
			if (!shell->line[i])
				return (1);
		}
		i++;
	}
	return (0);
}

int sep_cmd(t_pipe *list)
{
	
}

int	parsing(t_shell *shell)
{
	char		**str;
	t_pipe	*list;
	int 		i;

	if (check_quote(shell))
		return (error_msg(WUNQUOTE, 2));
	str = ft_split(shell->line, '|');
	i = 0;
	list = NULL;
	while(str[i])
	{
		list = add_cell(list, str[i], i);
		i++;
	}
	sep_cmd(list);
	print_list(list); //a enlever
	return (0);
}

t_pipe	*add_cell(t_pipe *list, char *cmd, int pos)
{
  t_pipe	*prec;
  t_pipe	*cur;
  t_pipe	*cell;
  int		i;

  cur = list;
  i = 0;
  cell = init_cell(cmd);
  if (list == NULL)
  	return (cell);
  while (i < pos)
  {
  	i++;
  	prec = cur;
  	cur = cur->next;
  }
  prec->next = cell;
  cell->next = cur;
  return (list);
}

void	print_list(t_pipe *list)
{
  int		i;

  i = 0;
  while (list)
  {
	if (i != 0)
  		printf("-----------------------------------\n");
  	printf("i = %d                            \n", i);
  	printf("list->cmd : %s            \n", list->cmd);
  	list = list->next;
  	i++;
  }
}

/*
mettre dans un char** chaque commande
arg[0] = echo
arg[1] = -n
arg[2] = bonjour 

|

char **
arg[0] = pwd
*/