/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:36 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 15:57:25 by ndemont          ###   ########.fr       */
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
	t_list	*pile_a1;
	t_list	*pile_a2;

	pile_a1 = *piles->a;
	pile_a2 = (*piles->a)->next;
	if (!piles)
		return ;
	if (!pile_a1)
		return ;
	ft_lstadd_front(piles->b, pile_a1);
	piles->a = &pile_a2;
}

void	rotate_b(t_piles *piles)
{
	t_list	*pile_first;
	t_list	*pile_second;

	if (!piles)
		return ;
	pile_first = *piles->b;
	if (!pile_first)
		return ;
	pile_second = (*piles->b)->next;
	if (!pile_second)
		return ;
	ft_lstadd_back(piles->b, pile_first);
	pile_first->next = 0;
	piles->b = &pile_second;
}