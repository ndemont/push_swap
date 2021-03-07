/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:15:55 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/07 11:52:23 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_up(t_piles *piles, int count)
{
	int	count2;

	count2 = count;
	while (count > 0)
	{
		rotate_b(piles, 1);
		count--;
	}
	push_b(piles);
	while (count < count2)
	{
		reverse_rotate_b(piles, 1);
		count++;
	}
}

void	move_down(t_piles *piles, int count)
{
	int count2;

	count2 = count;
	while (count < piles->len_b)
	{
		reverse_rotate_b(piles, 1);
		count++;
	}
	push_b(piles);
	while (count >= count2)
	{
		rotate_b(piles, 1);
		count--;
	}
}

void	heap_sort(t_piles *piles)
{
	int		count;
	int		count2;
	t_list	*pile_b;
	int		direction;

	while (piles->a)
	{
		if (!piles->b)
			push_b(piles);
		else
		{
			count = 0;
			direction = 0;
			pile_b = piles->b;
			if (pile_b)
			while (pile_b && *(long *)piles->a->content < *(long *)pile_b->content)
			{
				pile_b = pile_b->next;
				count++;
			}
			if (count <= (piles->len_b / 2))
				direction = 1;
			count2 = count;
			if (direction)
				move_up(piles, count);
			else
				move_down(piles, count);
		}
	}
	while(piles->b)
		push_a(piles);
}