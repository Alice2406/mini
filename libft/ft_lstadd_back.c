/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:43:58 by jmorvan           #+#    #+#             */
/*   Updated: 2023/02/08 11:40:55 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ls;

	ls = *lst;
	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			while (ls -> next != NULL)
				ls = ls -> next;
			ls -> next = new;
		}
	}
}
