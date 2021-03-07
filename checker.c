/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:31:31 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/07 14:15:31 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(t_piles *piles)
{

}

int		main(int ac, char *av)
{
	t_piles *piles;

	if (ac == 1)
		return (1);
	piles = init_piles();
	parsing(ac, av, piles);
	read_instructions(piles);
	free_piles(piles);
	return (0);
}