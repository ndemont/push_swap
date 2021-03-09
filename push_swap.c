/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:02:21 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/09 16:55:46 by ndemont          ###   ########.fr       */
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
	//heap_sort(piles);
	bubble_sort(piles);
	free_piles(piles);
	return (0);
}
