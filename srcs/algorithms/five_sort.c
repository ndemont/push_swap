/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:44:35 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/21 23:48:09 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_pos_max(t_list *list, long max)
{
	t_list	*temp;
	long 	count;

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

void	move_up4(t_piles *piles, int count)
{
	int	count2;

	count2 = count;
	while (count > 0)
	{
		rotate_a(piles, 1, piles->fd);
		count--;
	}
}

void	move_down4(t_piles *piles, int count)
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
		move_up4(piles, count);
	else
		move_down4(piles, count);
}

//static int	check_max(t_piles *piles)
//{
//	long	n_b1;

//	n_b1 = *(long *)piles->b->content;
//	if (n_b1 == piles->max)
//	{
//		push_a(piles, 1, piles->fd);
//		rotate_a(piles, 1, piles->fd);
//	}
//	return (0);
//}

void	five_sort(t_piles *piles)
{
	long	n_b1;
	long	n_b2;
	long	last;

	(void)n_b2;
	if (ascending_order(piles->a))
		return ;
	push_b(piles, 1, piles->fd);
	if (piles->len_total == 5)
		push_b(piles, 1, piles->fd);
	three_sort(piles);
	//check_max(piles);
	//while (piles->len_b)
	last = *(long *)piles->a->next->next->content;
	while (piles->len_b)
	{
		n_b1 = *(long *)piles->b->content;
		if (piles->len_b == 2)
		{
			n_b2 = *(long *)piles->b->next->content;
			if (n_b2 < *(long *)piles->a->content)
			{	
				swap_b(piles, 1, piles->fd);
				push_a(piles, 1, piles->fd);
			}
		}
		if (n_b1 < *(long *)piles->a->content)
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
