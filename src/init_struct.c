/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:10:55 by aniezgod          #+#    #+#             */
/*   Updated: 2023/10/18 18:13:45 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_pipe *init_cell(char *line)
{
	t_pipe *cell;

	cell = malloc(sizeof(t_pipe));
	if (!cell)
		return (NULL);
	cell->prev = NULL;
	cell->next = NULL;
	cell->cmd = line;
	return (cell);
}
