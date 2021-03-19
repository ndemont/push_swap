/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:15:55 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 21:32:48 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_pile_b(t_piles *piles, long count, int i)
{
	while (count)
	{
		if (*(long *)piles->a->content <= piles->mediane[i])
			push_b(piles, 1);
		else
			rotate_a(piles, 1);
		count--;
	}
}

void	fill_pile_a(t_piles *piles, int *remaining)
{
	t_elem	min;
	t_elem	max;
	t_elem	final;

	while (piles->b)
	{
		find_position(piles->b, &min.pos, &max.pos);
		count_moves(&min, &max, piles->len_b);
		final = max;
		if (min.moves < max.moves)
			final = min;
		else
			*remaining += 1;
		while (final.moves > 0)
		{
			if (!final.dir)
				rotate_b(piles, 1);
			else
				reverse_rotate_b(piles, 1);
			final.moves--;
		}
		push_a(piles, 1);
		if (final.pos != max.pos && piles->len_a > 1)
			rotate_a(piles, 1);
	}
}

void	place_pile_a(t_piles *piles, int i)
{
	long	move_up;
	long	move_down;

	if (i != 0 && i != piles->steps - 1)
	{
		move_up = piles->mediane[i - 1];
		move_down = piles->len_total - piles->mediane[i];
		if (move_up < move_down)
		{
			while (move_up > 0)
			{
				rotate_a(piles, 1);
				move_up--;
			}
		}
		else
		{
			while (move_down > 0)
			{
				reverse_rotate_a(piles, 1);
				move_down--;
			}
		}
	}
}

void	replace_pile_a(t_piles *piles, int i, int *remaining)
{
	while (i < (piles->steps - 1) && *remaining)
	{
		rotate_a(piles, 1);
		*remaining -= 1;
	}
}

void	thib_sort(t_piles *piles)
{
	int count;
	int remaining;
	int i;

	i = 0;
	count = piles->len_total;
	set_steps(piles);
	while (i < piles->steps)
	{
		remaining = 0;
		fill_pile_b(piles, count, i);
		place_pile_a(piles, i);
		fill_pile_a(piles, &remaining);
		replace_pile_a(piles, i, &remaining);
		count = piles->len_total - piles->mediane[i];
		i++;
	}
	put_min_first(piles);
}
