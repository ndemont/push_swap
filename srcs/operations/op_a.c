/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:56 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 12:52:46 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *piles)
{
	t_list	*pile_a;
	long	*tmp;

	if (!piles)
		return ;
	pile_a = *(piles->a);
	if (!pile_a)
		return ;
	if (pile_a->next)
	{
		tmp = pile_a->content;
		pile_a->content = pile_a->next->content;
		pile_a->next->content = tmp;
	}
}


void	push_a(t_piles *piles)
{
	t_list *tmpb;

	if (!piles)
		return ;
	if (!*(piles->b))
		return ;
	tmpb = *(piles->b);
	piles->b = &(*(piles->b))->next;
	tmpb->next = *(piles->a);
	piles->a = &(tmpb);
}
