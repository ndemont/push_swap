/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:02:21 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/22 20:53:18 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
int		main(int ac, char **av)
{
	t_piles *piles;

	(void)av;
	if (ac == 1)
		return (1);
	piles = init_piles();
	piles->fd = 1;
	parsing(ac, av, piles);
	if (!piles->dst && piles->v)
		print_errors(piles, "-v can not be activated without -dst");
	if (!ascending_order(piles->a))
	{
		if (piles->len_total == 2)
			rotate_a(piles, 1, piles->fd);
		else if (piles->len_total == 3)
			three_sort(piles);
		else if (piles->len_total <= 5)
			five_sort(piles);
		else
			quick_sort(piles);
	}
	free_piles(piles);
	return (0);
}
