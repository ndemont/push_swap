/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_min_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:39:18 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/22 19:40:08 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_pos_max(t_list *list, long max)
{
	t_list	*temp;
	long	count;

	temp = list;
	count = 0;
	while (temp)
	{
		if (max == *(long *)temp->content)
			return (count);
		count++;
		temp = temp->next;
	}
	return (-1);
}

void	move_up(t_piles *piles, int count)
{
	int	count2;

	count2 = count;
	while (count > 0)
	{
		rotate_a(piles, 1, piles->fd);
		count--;
	}
}

void	move_down(t_piles *piles, int count)
{
	int count2;

	count2 = count;
	while (count > 0)
	{
		reverse_rotate_a(piles, 1, piles->fd);
		count--;
	}
}

void	put_min_first(t_piles *piles)
{
	long pos;
	long count;
	long direction;

	pos = find_pos_max(piles->a, piles->min);
	if (pos > (piles->len_a / 2) + 1)
	{
		direction = 0;
		count = piles->len_a - pos;
		if (count < 0)
			count = 0;
	}
	else
	{
		direction = 1;
		count = pos;
	}
	if (direction)
		move_up(piles, count);
	else
		move_down(piles, count);
}
