/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:44:35 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/22 19:42:49 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_pileb(t_piles *piles)
{
	long	last;

	last = *(long *)piles->a->next->next->content;
	while (piles->len_b)
	{
		if (piles->len_b == 2)
		{
			if (*(long *)piles->b->next->content < *(long *)piles->a->content)
			{
				swap_b(piles, 1, piles->fd);
				push_a(piles, 1, piles->fd);
			}
		}
		if (*(long *)piles->b->content < *(long *)piles->a->content)
			push_a(piles, 1, piles->fd);
		if (piles->len_b)
		{
			if (*(long *)piles->a->content == last)
			{
				rotate_a(piles, 1, piles->fd);
				break ;
			}
			rotate_a(piles, 1, piles->fd);
		}
	}
}

void		five_sort(t_piles *piles)
{
	if (ascending_order(piles->a))
		return ;
	push_b(piles, 1, piles->fd);
	if (piles->len_total == 5)
		push_b(piles, 1, piles->fd);
	three_sort(piles);
	insert_pileb(piles);
	if (piles->len_b)
	{
		push_a(piles, 1, piles->fd);
		if (piles->len_b)
		{
			if (*(long *)piles->b->content < *(long *)piles->a->content)
			{
				push_a(piles, 1, piles->fd);
				rotate_a(piles, 1, piles->fd);
			}
			else
			{
				rotate_a(piles, 1, piles->fd);
				push_a(piles, 1, piles->fd);
			}
		}
	}
	put_min_first(piles);
}
