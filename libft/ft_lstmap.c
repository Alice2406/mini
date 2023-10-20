/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:42:40 by jmorvan           #+#    #+#             */
/*   Updated: 2023/01/25 17:13:26 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*lstnew;
	t_list	*lststart;

	if (!lst || !f)
		return (NULL);
	lstnew = ft_lstnew(f(lst -> content));
	if (!lstnew)
		return (NULL);
	lststart = lstnew;
	lst = lst -> next;
	while (lst)
	{
		lstnew = ft_lstnew(f(lst -> content));
		if (!lstnew)
		{
			ft_lstclear(&lststart, d);
			return (NULL);
		}
		lst = lst -> next;
		ft_lstadd_back(&lststart, lstnew);
	}
	return (lststart);
}
