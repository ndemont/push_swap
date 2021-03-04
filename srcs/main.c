/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:02:21 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 16:28:48 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_piles *piles;

	piles = init_piles();
	parsing(ac, av, piles);
	print_piles(piles);
	swap_a(piles);
	print_piles(piles);
	rotate_a(piles);
	print_piles(piles);
	rotate_a(piles);
	print_piles(piles);
	rotate_a(piles);
	print_piles(piles);
	return (0);
}
