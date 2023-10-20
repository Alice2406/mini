/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:10:55 by aniezgod          #+#    #+#             */
/*   Updated: 2023/10/20 14:49:54 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token *init_cell(char *line)
{
	t_token *cell;

	cell = malloc(sizeof(t_token));
	if (!cell)
		return (NULL);
	cell->type = 0;
	cell->right = NULL;
	cell->arg[0] = line;
	cell->down = NULL;
	return (cell);
}
