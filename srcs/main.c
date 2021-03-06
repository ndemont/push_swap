/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:02:21 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/06 19:06:42 by ndemont          ###   ########.fr       */
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
	print_piles(piles);
	push_a(piles);
	rotate_a(piles, 1);
	push_b(piles);
	reverse_rotate_a(piles, 1);
	push_b(piles);
	reverse_rotate_b(piles, 1);
	rotate_b(piles, 1);
	free_piles(piles);
	return (0);
}
