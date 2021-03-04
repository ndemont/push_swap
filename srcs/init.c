/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:24:11 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 16:28:38 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**new_pile()
{
	t_list **pile;

	pile = malloc(sizeof(t_list*));
	if (!pile)
		return (0);
	return (pile);
}

t_piles *init_piles(void)
{
	t_list **pile_a;
	t_list **pile_b;
	t_piles *piles;

	piles = malloc(sizeof(t_piles*));
	if (!piles)
		print_errors(piles);
	piles->a = 0;
	piles->b = 0;
	pile_a = new_pile();
	if (!pile_a)
		print_errors(piles);
	piles->a = pile_a;
	pile_b = new_pile();
	if (!pile_b)
		print_errors(piles);
	piles->b = pile_b;
	return (piles);
}
