/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapsort_opti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:15:55 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/10 12:26:59 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_up2(t_piles *piles, int count)
{
	int	count2;

	count2 = count;
	while (count > 0)
	{
		rotate_b(piles, 1);
		count--;
	}
	push_b(piles, 1);
}

void	move_down2(t_piles *piles, int count)
{
	int count2;

	count2 = count;
	while (count < piles->len_b)
	{
		reverse_rotate_b(piles, 1);
		count++;
	}
	push_b(piles, 1);
}

void	move_up3(t_piles *piles, int count)
{
	int	count2;

	count2 = count;
	while (count > 0)
	{
		rotate_b(piles, 1);
		count--;
	}
	push_b(piles, 1);
}

void	move_down3(t_piles *piles, int count)
{
	int count2;

	count2 = count;
	while (count < piles->len_b)
	{
		reverse_rotate_b(piles, 1);
		count++;
	}
	push_b(piles, 1);
}

long	find_pos_min(t_list *list, long min)
{
	t_list	*temp;
	long 	count;

	temp = list;
	count = 0;
	while (temp)
	{
		if (min == *(long *)temp->content)
			return (count);
		count++;
		temp = temp->next;
	}
	return (-1);
}

long	find_pos_max(t_list *list, long max)
{
	t_list	*temp;
	long 	count;

	temp = list;
	count = 1;
	while (temp)
	{
		if (max == *(long *)temp->content)
			return (count);
		count++;
		temp = temp->next;
	}
	return (-1);
}

long	find_pos_middle(t_list *list, long nb)
{
	t_list	*temp;
	long 	pos;

	temp = list;
	pos = 1;
	while (temp->next)
	{
		if (nb < *(long *)list->content && nb > *(long *)list->next->content)
			return (pos);
		pos++;
		temp = temp->next;
	}
	return (-1);
}

long	find_last(t_list *list)
{
	long	last;
	t_list	*tmp;

	tmp = list;
	while (list->next)
		list = list->next;
	last = *(long *)list->content;
	return (last);
}

int		find_pos(long min, long max, t_piles *piles)
{
	long	pos;
	long	first;
	long	last;

	first = *(long *)piles->b->content;
	last = find_last(piles->b);
	if (piles->len_b > 1 && (*(long *)piles->a->content > max | *(long *)piles->a->content < min))
		pos = find_pos_min(piles->b, min);
	if (*(long *)piles->a->content > first && *(long *)piles->a->content < last)
		pos = 0;
	else
		pos = find_pos_middle(piles->b, *(long *)piles->a->content);
	return (pos);
}

void reverse_range_pile(t_piles *piles, long max)
{
	long	pos;
	long	count;
	int		direction;

	pos = find_pos_max(piles->b, max);
	if (pos > piles->len_b / 2)
	{
		direction = 0;
		count = piles->len_b - pos;
	}
	else
	{
		direction = 1;
		count = pos;
	}
	if (direction)
		move_up3(piles, count);
	else
		move_down3(piles, count);

}

void	heap_sort_magic(t_piles *piles)
{
	int		count;
	long	max;
	long	min;
	long	pos;
	int		direction;

	while (piles->a)
	{
		if (!piles->b)
		{
			min = *(long *)piles->a->content;
			max = *(long *)piles->a->content;
			push_b(piles, 1);
		}
		else
		{
			pos = find_pos(min, max, piles);
			if (pos > piles->len_b / 2)
			{
				direction = 0;
				count = piles->len_b - pos -1;
			}
			else
			{
				direction = 1;
				count = pos;
			}
			if (direction)
				move_up2(piles, pos);
			else
				move_down2(piles, pos);
		}
	}
	reverse_range_pile(piles, max);
	while(piles->b)
		push_a(piles, 1);
}
