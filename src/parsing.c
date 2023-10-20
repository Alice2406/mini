/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:14:25 by jmorvan           #+#    #+#             */
/*   Updated: 2023/10/20 14:49:09 by aniezgod         ###   ########.fr       */
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

int	parsing(t_shell *shell)
{
	char		**str;
	t_token		*list;
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
	print_list(list); //a enlever
	return (0);
}

t_token	*add_cell(t_token *list, char *cmd, int pos)
{
  t_token	*prec;
  t_token	*cur;
  t_token	*cell;
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
  	cur = cur->down;
  }
  prec->down = cell;
  cell->down = cur;
  return (list);
}

void	print_list(t_token *list)
{
  int		i;

  i = 0;
  while (list)
  {
	if (i != 0)
  		printf("-----------------------------------\n");
  	printf("i = %d                            \n", i);
  	printf("list->cmd : %s            \n", list->arg[0]);
  	list = list->down;
  	i++;
  }
}

