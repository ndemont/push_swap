/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:27:40 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 21:36:56 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	find_median(int count, long min, t_piles *piles)
{
	t_list	*list;
	long	next_min;
	long	nb;
	int		i;

	i = 0;
	while (i < count - 1)
	{
		next_min = piles->max;
		list = piles->a;
		while (list)
		{
			nb = *(long *)list->content;
			if (nb > min && nb < next_min)
				next_min = nb;
			list = list->next;
		}
		min = next_min;
		i++;
	}
	return (min);
}

void		set_steps(t_piles *piles)
{
	long	count;
	long	mod;
	long	min;
	int		i;

	piles->steps = piles->len_total / 80;
	mod = piles->len_total % 80;
	if (mod || !piles->steps)
		piles->steps++;
	piles->mediane = malloc(sizeof(long) * piles->steps);
	if (!piles->mediane)
		print_errors(piles);
	piles->mediane[piles->steps - 1] = piles->max;
	min = piles->min;
	i = 0;
	while (i < piles->steps - 1)
	{
		count = piles->len_total / piles->steps;
		if (i == 0)
			count += (piles->len_total % piles->steps);
		piles->mediane[i] = find_median(count, min, piles);
		min = piles->mediane[i] + 1;
		i++;
	}
}
