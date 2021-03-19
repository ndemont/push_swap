/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:27:10 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 21:33:16 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	set_min(long nb, long min, long *pos_min, int i)
{
	if (nb < min)
	{
		*pos_min = i;
		min = nb;
	}
	return (min);
}

long	set_max(long nb, long max, long *pos_max, int i)
{
	if (nb > max)
	{
		*pos_max = i;
		max = nb;
	}
	return (max);
}

void	find_position(t_list *pile, long *pos_min, long *pos_max)
{
	t_list	*list;
	long	nb;
	long	min;
	long	max;
	int		i;

	list = pile;
	i = 0;
	while (list)
	{
		nb = *(long *)list->content;
		if (i == 0)
		{
			min = nb;
			max = nb;
			*pos_min = i;
			*pos_max = i;
		}
		min = set_min(nb, min, pos_min, i);
		max = set_max(nb, max, pos_max, i);
		i++;
		list = list->next;
	}
}

void	count_moves(t_elem *min, t_elem *max, int len)
{
	min->moves = len - min->pos;
	min->dir = 1;
	if (min->pos < len / 2)
	{
		min->moves = min->pos;
		min->dir = 0;
	}
	max->moves = len - max->pos;
	max->dir = 1;
	if (max->pos < len / 2)
	{
		max->moves = max->pos;
		max->dir = 0;
	}
}
