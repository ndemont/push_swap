/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:15:55 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 17:10:32 by ndemont          ###   ########.fr       */
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
	while (count > 0)
	{
		reverse_rotate_b(piles, 1);
		count--;
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
}

void	move_down3(t_piles *piles, int count)
{
	int count2;

	count2 = count;
	while (count > 0)
	{
		reverse_rotate_b(piles, 1);
		count--;
	}
}

void	move_up4(t_piles *piles, int count)
{
	int	count2;

	count2 = count;
	while (count > 0)
	{
		rotate_a(piles, 1);
		count--;
	}
}

void	move_down4(t_piles *piles, int count)
{
	int count2;

	count2 = count;
	while (count > 0)
	{
		reverse_rotate_a(piles, 1);
		count--;
	}
}

long	find_pos_min(t_list *list, long min, t_piles *piles)
{
	t_list	*temp;
	long 	count;

	temp = list;
	count = 1;
	while (temp)
	{
		if (min == *(long *)temp->content)
		{
			if (count == piles->len_b)
				count = 0;
			return (count);
		}
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

long	find_pos_middle(t_list *list, long nb, long min)
{
	t_list	*temp;
	long 	pos;

	temp = list;
	pos = 1;
	while (temp->next)
	{
		if (nb < *(long *)temp->content && nb > *(long *)temp->next->content)
			return (pos);
		else if (nb > *(long *)temp->content && nb < *(long *)temp->next->content && *(long *)temp->content != min) 
			return (pos);
		pos++;
		temp = temp->next;
	}
	return (0);
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
	long	len;

	first = *(long *)piles->b->content;
	last = find_last(piles->b);
	len = piles->len_b;
	(void)max; 
	(void)min;
	if (piles->len_b == 1)
	{
		pos = 0;
	}
	else if (*(long *)piles->a->content > max | *(long *)piles->a->content < min)
	{
		pos = find_pos_min(piles->b, min, piles);
	}
	else
	{
		pos = find_pos_middle(piles->b, *(long *)piles->a->content, min);
	}	
	return (pos);
}

void reverse_range_pile(t_piles *piles, long max)
{
	long	pos;
	long	count;
	int	direction;

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

void	put_min_last(t_piles *piles)
{
	if (*(long *)piles->a->content == piles->min)
		rotate_a(piles, 1);
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

void	put_max_first(t_piles *piles)
{
	long pos;
	long count;
	long direction;

	pos = find_pos_max(piles->a, piles->max);
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

void	heap_sort_magic(t_piles *piles)
{
	long	count;
	long	last;
	long	max;
	long	min;
	long	pos;
	long	i;
	int		check;
	int		direction;
	long	nb;
	
	i = piles->len_total;
	check = 0;
	min = 0;
	max = 0;
	while (i > 0)
	{
		nb = *(long *)piles->a->content;
		if (nb == piles->min || nb == piles->max)
		{
			if (nb == piles->min)
				piles->prev_min = nb; 
			else if (nb == piles->max)
				piles->prev_min = piles->max;
			rotate_a(piles, 1);
		}
		else if (nb > piles->prev_min)
		{
			piles->prev_min = nb;
			rotate_a(piles, 1);
		}
		else if (!check)
		{
			min = nb;
			max = nb;
			check = 1;
			push_b(piles, 1);
		}
		else
		{
			pos = find_pos(min, max, piles);
			if (pos > (piles->len_b / 2) + 1)
			{
				direction = 0;
				count = piles->len_b - pos;
				if (count < 0)
					count = 0;
			}
			else
			{
				direction = 1;
				count = pos;
			}
			if (nb < min)
				min = nb;
			if (nb > max)
				max = nb;
			if (direction)
				move_up2(piles, count);
			else
				move_down2(piles, count);
		}
		i--;
	}
	reverse_range_pile(piles, max);
	put_max_first(piles);
	(void)last;
	while(piles->b)
	{
		last = find_last(piles->a);
		while((*(long *)piles->b->content < last))
		{
			reverse_rotate_a(piles, 1);
			last = find_last(piles->a);
		}
		push_a(piles, 1);
	}
	put_min_first(piles);
}
