/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:42:20 by jmorvan           #+#    #+#             */
/*   Updated: 2023/06/19 14:17:45 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
Show the carbage collector GC.
*/
// void	show_gc(t_garbage *gc)
// {
// 	int	i = 0;
// 	printf("\n");
// 	if (!gc)
// 		printf("garbage collector is empty !\n");
// 	while (gc)
// 	{
// 		i++;
// 		printf("gc : %d\nid : %d\nalloc :%p\n", i, gc->id, gc->alloc);
// 		printf("__________________\n");
// 		gc = gc->next;
// 	}
// }

/*
Remove and free the element which contains the address ADRR
in the garbage collector GC.
*/
void	free_in_gc(t_garbage **gc, void *addr)
{
	t_garbage	*here;

	here = *gc;
	while (here)
	{
		if (here->alloc == addr)
		{
			if (here == *gc)
				*gc = (*gc)->next;
			if (here->last)
				here->last->next = here->next;
			if (here->next)
				here->next->last = here->last;
			free(here->alloc);
			free(here);
			return ;
		}
		else
			here = here->next;
	}
}

/*
Allocate SIZE bytes of memory and add it to the garbage collector GC
with the id ID.
*/
void	*gc_malloc(size_t size, t_garbage **gc, int id)
{
	t_garbage	*grb;
	void		*ptr;

	grb = malloc(sizeof(*grb) * 1);
	ptr = malloc(size);
	if (!ptr || !grb)
		return (NULL);
	grb->alloc = ptr;
	grb->id = id;
	grb->next = NULL;
	grb->last = NULL;
	if (!(*gc))
		*gc = grb;
	else
	{
		grb->next = *gc;
		(*gc)->last = grb;
		*gc = grb;
	}
	return (ptr);
}

/*
Clean the garbage collector GC of the garbage with the same id
of ID or clean all the garbage if ID is 0. 
*/
void	clean_gc(t_garbage **gc, int id)
{
	t_garbage	*here;
	t_garbage	*tmp;

	here = *gc;
	while (here)
	{
		while (here && (!id || here->id > 0))
		{
			if (here == *gc)
				*gc = (*gc)->next;
			if (here->last)
				here->last->next = here->next;
			if (here->next)
				here->next->last = here->last;
			tmp = here->next;
			free(here->alloc);
			free(here);
			here = tmp;
		}
		if (here)
			here = here->next;
	}
}
