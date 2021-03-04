/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:36 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 13:00:26 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_piles *piles)
{
	t_list	*pile_b;
	long	*tmp;

	if (!piles)
		return ;
	pile_b = *(piles->b);
	if (!pile_b)
		return ;
	if (pile_b->next)
	{
		tmp = pile_b->content;
		pile_b->content = pile_b->next->content;
		pile_b->next->content = tmp;
	}
}

void	push_b(t_piles *piles)
{
	t_list *tmpa;
	t_list *tmp2;

	if (!piles)
		return ;
	if (!*(piles->a))
		return ;
	tmpa = *(piles->a);
	printf("add first elem a = %p\n", *(piles->a));
	printf("add first elem b = %p\n", *(piles->b));
	tmp2 = (*(piles->a))->next;
	printf("add new first elem a = %p\n", *(piles->a));
	tmpa->next = *(piles->b);
	printf("add new second elem b = %p\n", tmpa->next);
	piles->b = &(tmpa);
	piles->a = &tmp2;
	printf("add new first elem a = %p\n", *(piles->a));
	printf("add new first elem b = %p\n", *(piles->b));
}