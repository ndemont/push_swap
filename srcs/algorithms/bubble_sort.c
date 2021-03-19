/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:15:55 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 22:09:56 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_piles *piles)
{
	int			count1;
	int			count2;
	t_list		*list;

	count1 = 1;
	while (count1 < piles->len_total)
	{
		if (ascending_order(piles->a))
			return ;
		list = piles->a;
		count2 = 1;
		while (count2 < piles->len_total)
		{
			if (ascending_order(piles->a))
				return ;
			if (*(long *)list->content > *(long *)list->next->content)
				swap_a(piles, 1, piles->fd);
			rotate_a(piles, 1, piles->fd);
			list = piles->a;
			count2++;
		}
		rotate_a(piles, 1, piles->fd);
		count1++;
	}
}
