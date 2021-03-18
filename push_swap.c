/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:02:21 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/18 12:13:15 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
int		main(int ac, char **av)
{
	t_piles *piles;

	if (ac == 1)
		return (1);
	piles = init_piles();
	parsing(ac, av, piles);
	if (!ascending_order(piles->a))
	{
		if (piles->len_total == 2)
			rotate_a(piles, 1);
		else if (piles->len_total == 3)
			three_sort(piles);
		else
		{
			//heap_sort_magic(piles);
			thib_sort(piles);
		}
	}
	free_piles(piles);
	return (0);
}
